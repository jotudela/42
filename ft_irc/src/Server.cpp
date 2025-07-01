#include "../inc/Server.hpp"
#include "../inc/Admin.hpp"

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::remove;
using std::istringstream;

Server::Server( int port, string passWord ) : _port(port), _serverFd(-1),
_epollFD(-1), _passWord(passWord), _running(true)
{
    string nickName;
    string userName;

    _admin.setAdminStatus();

    cout << "Enter admin nick name : ";
    getline(cin, nickName);
    cout << endl << "Enter admin user name : ";
    getline(cin, userName);
    cout << endl;
    cout << "Enter the Topic of the channel : ";
    getline(cin, _topic);
    cout << endl;

    _admin.setAdminNames(nickName, userName);
}

Server::~Server(){}

const string& Server::getPassWord() const
{
    return _passWord;
}

const string& Server::getTopic() const
{
    return _topic;
}

int Server::getPort() const
{
    return _port;
}

const std::string& Server::getAdminNickName() const
{
    return _admin.getNickName();
}

const std::string& Server::getAdminUserName() const
{
    return _admin.getUserName();
}

const std::string& Server::getStaffNickName() const
{
    return _admin.getNickName();
}

const std::string& Server::getStaffUserName() const
{
    return _admin.getUserName();
}

void Server::makeNonBlocking( int fd )
{
    fcntl(fd, F_SETFL, O_NONBLOCK);
}

void Server::setUpServer()
{
    // Création du socket d'écoute
    _serverFd = socket(AF_INET, SOCK_STREAM, 0);
    this->makeNonBlocking(_serverFd);

    _opt = 1;
    setsockopt(_serverFd, SOL_SOCKET, SO_REUSEADDR, &_opt, sizeof(_opt));

    _serverAddr.sin_family = AF_INET;
    _serverAddr.sin_addr.s_addr = INADDR_ANY;
    _serverAddr.sin_port = htons(_port);

    bind(_serverFd, (sockaddr*)&_serverAddr, sizeof(_serverAddr));
    listen(_serverFd, SOMAXCONN);

    // Création de l'instance epoll
    _epollFD = epoll_create1(0);

    // Ajout du socket d'écoute à epoll
    _events[0].events = EPOLLIN;
    _events[0].data.fd = _serverFd;
    epoll_ctl(_epollFD, EPOLL_CTL_ADD, _serverFd, &_events[0]);

    // Ajout de l'entrée standard (fd 0)
    this->makeNonBlocking(STDIN_FILENO);
    epoll_event stdin_ev;
    memset(&stdin_ev, 0, sizeof(stdin_ev));
    stdin_ev.events = EPOLLIN;
    stdin_ev.data.fd = STDIN_FILENO;
    epoll_ctl(_epollFD, EPOLL_CTL_ADD, STDIN_FILENO, &stdin_ev);
}

int Server::createNewUser()
{
    int client_fd = accept(_serverFd, NULL, NULL);
    if (client_fd == -1)
    {
        perror("accept");
        return -1;
    }

    makeNonBlocking(client_fd);

    epoll_event client_event;
    memset(&client_event, 0, sizeof(client_event));
    client_event.events = EPOLLIN | EPOLLET;
    client_event.data.fd = client_fd;

    if (epoll_ctl(_epollFD, EPOLL_CTL_ADD, client_fd, &client_event) == -1)
    {
        perror("epoll_ctl: client_fd");
        close(client_fd);
        return -1;
    }

    _users[client_fd] = new User();
    _userStates[client_fd] = WAIT_NICK;
    _tempNick[client_fd] = "";
    _tempUser[client_fd] = "";
    return 0;
}

int Server::commandAdminStaff()
{
    string input;
    getline(cin, input);
    if (input == "QUIT")
    {
        cout << "Shutting down server.\n";
        _running = false;
        return -1;
    }
    else
        cout << "[Server command] " << input << endl;
    return 0;
}

int Server::commandUser( int event_fd )
{
    memset(_buffer, 0, IRC_MESSAGE_MAX);
    int count = read(event_fd, _buffer, IRC_MESSAGE_MAX);
    if (count <= 0)
    {
        if (_users[event_fd]->getStatus())
            cout << "Client disconnected: " << _users[event_fd]->getNickName() << endl;

        close(event_fd);
        epoll_ctl(_epollFD, EPOLL_CTL_DEL, event_fd, NULL);
        delete _users[event_fd];
        _users.erase(event_fd);
        _userStates.erase(event_fd);
        _tempNick.erase(event_fd);
        _tempUser.erase(event_fd);
        return -1;
    }

    string input(_buffer, count);
    input.erase(remove(input.begin(), input.end(), '\n'), input.end());
    input.erase(remove(input.begin(), input.end(), '\r'), input.end());

    switch (_userStates[event_fd])
    {
        case WAIT_NICK:
        {
            istringstream iss(input);
            string command;
            iss >> command;

            string nick;
            getline(iss, nick);
            nick.erase(0, nick.find_first_not_of(" \t"));

            if (command != "NICK" || nick.empty())
            {
                const char* msg = ":server 431 * :No nickname given\r\n";
                write(event_fd, msg, strlen(msg));
            }
            else
            {
                _tempNick[event_fd] = nick;
                _userStates[event_fd] = WAIT_USER;
            }
            break;
        }
        case WAIT_USER:
        {
            istringstream iss(input);
            string command, username, hostname, servername, realname;
            iss >> command >> username >> hostname >> servername;
            getline(iss, realname);
            if (!realname.empty() && realname[0] == ' ')
                realname.erase(0,1);
            if (command != "USER" || username.empty())
            {
                const char* msg = ":server 461 * USER :Not enough parameters\r\n";
                write(event_fd, msg, strlen(msg));
            }
            else
            {
                _tempUser[event_fd] = username;
                _userStates[event_fd] = REGISTERED;
                _users[event_fd]->setNickName(_tempNick[event_fd]);
                _users[event_fd]->setUserName(_tempUser[event_fd]);
                _users[event_fd]->setStatus(false);

                string welcome = ":server 001 " + _tempNick[event_fd] + " :Welcome to the IRC server!\r\n";
                write(event_fd, welcome.c_str(), welcome.size());

                _tempNick.erase(event_fd);
                _tempUser.erase(event_fd);
            }
            break;
        }
        case REGISTERED:
        {
            istringstream iss(input);
            string command;
            iss >> command;

            if (command == "JOIN")
            {
                string channel;
                getline(iss, channel);
                channel.erase(0, channel.find_first_not_of(" \t"));
                if (channel.empty())
                {
                    const char* msg = ":server 461 * JOIN :Not enough parameters\r\n";
                    write(event_fd, msg, strlen(msg));
                    break;
                }
                if (channel != this->getTopic())
                {
                    string msg = ":server 403 * " + channel + " :No such channel\r\n";
                    write(event_fd, msg.c_str(), msg.size());
                    break;
                }

                channel = "Please enter password : ";
                write(event_fd, channel.c_str(), channel.length());
                _userStates[event_fd] = WAIT_PASSWORD;
            }
            else
            {
                string msg = ":server 421 * " + command + " :Unknown command\r\n";
                write(event_fd, msg.c_str(), msg.size());
            }
            break;
        }
        case WAIT_PASSWORD:
        {
            string password = input;
            password.erase(remove(password.begin(), password.end(), '\n'), password.end());
            password.erase(remove(password.begin(), password.end(), '\r'), password.end());

            if (password == this->getPassWord())
            {
                string msg = "✅ You have joined channel " + this->getTopic() + "\r\n";
                write(event_fd, msg.c_str(), msg.size());

                cout << "User " << _users[event_fd]->getNickName()
                            << " joined channel: " << this->getTopic() << endl;

                _users[event_fd]->setStatus(true);
                _userStates[event_fd] = JOINED;
            }
            else
            {
                const char* msg = "❌ Password invalid!\r\n";
                write(event_fd, msg, strlen(msg));
                _userStates[event_fd] = REGISTERED;
            }
            break;
        }
        case JOINED:
        {
            istringstream iss(input);
            string command, target;

            iss >> command >> target;

            // Vérification : command et target doivent exister
            if (command != "PRIVMSG" || target.empty())
            {
                string err = ":server 461 * PRIVMSG :Not enough parameters\r\n";
                write(event_fd, err.c_str(), err.size());
                break;
            }

            // Nettoyage
            target.erase(0, target.find_first_not_of(" \t"));
            target.erase(target.find_last_not_of(" \t") + 1);
            if (!target.empty() && target[0] == ':')
                target.erase(0, 1);

            // Récupération du message
            string message;
            getline(iss, message);
            if (!message.empty())
            {
                message.erase(0, message.find_first_not_of(" \t"));
                if (message[0] == ':')
                    message.erase(0, 1);
            }

            if (target == ("#" + this->getTopic()))
            {
                string fullMsg = _users[event_fd]->getNickName() + " from " + target + " : " + message + "\r\n";

                for (std::map<int, User*>::iterator it = _users.begin(); it != _users.end(); ++it)
                {
                    int fd = it->first;
                    if (_userStates[fd] == JOINED && fd != event_fd)
                        write(fd, fullMsg.c_str(), fullMsg.size());
                }
                for (std::map<int, Admin*>::iterator it = _staffs.begin(); it != _staffs.end(); ++it)
                {
                    int fd = it->first;
                    if (fd != event_fd)
                        write(fd, fullMsg.c_str(), fullMsg.size());
                }
            }
            else if (_users.count(event_fd))  // On vérifie que l'expéditeur existe
            {
                // Recherche d'un destinataire avec ce nick
                int receiver_fd = -1;
                for (std::map<int, User*>::iterator it = _users.begin(); it != _users.end(); ++it)
                {
                    if (it->second->getNickName() == target && _userStates[it->first] == JOINED)
                    {
                        receiver_fd = it->first;
                        break;
                    }
                }

                if (receiver_fd != -1)
                {
                    string fullMsg = _users[event_fd]->getNickName() + " to you " + ": " + message + "\r\n";
                    write(receiver_fd, fullMsg.c_str(), fullMsg.size());
                }
                else
                {
                    string err = ":server 401 " + target + " :No such nick/channel\r\n";
                    write(event_fd, err.c_str(), err.size());
                }
            }
            break;
        }
        default:
            break;
    }
    return 0;
}

void Server::run()
{
    while (_running)
    {
        int n = epoll_wait(_epollFD, _events, MAX_EVENTS, -1);
        if (n == -1)
        {
            perror("epoll_wait");
            break;
        }

        for (int i = 0; i < n; ++i)
        {
            int event_fd = _events[i].data.fd;

            if (event_fd == _serverFd)
            {
                if (this->createNewUser() == -1)
                    continue;
            }
            else if (event_fd == STDIN_FILENO)
            {
                if (this->commandAdminStaff() == -1)
                    continue;
            }
            else
            {
                if (this->commandUser(event_fd) == -1)
                    continue;
            }
        }
    }
    close(_epollFD);
    close(_serverFd);
}
