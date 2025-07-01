#include "../inc/Server.hpp"
#include "../inc/Admin.hpp"

using std::string;
using std::cout;
using std::endl;
using std::cin;

Server::Server( int port, string passWord ) : _port(port), _serverFd(-1),
_epollFD(-1), _passWord(passWord), _running(true)
{
    string nickName;
    string userName;

    _admin.setAdminStatus();

    cout << "Enter admin nick name : ";
    cin >> nickName;
    cout << endl << "Enter admin user name : ";
    cin >> userName;
    cout << endl;
    cout << "Enter the Topic of the Server : ";
    cin >> _topic;
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
                // Nouvelle connexion
                int client_fd = accept(_serverFd, NULL, NULL);
                if (client_fd == -1)
                {
                    perror("accept");
                    continue;
                }

                makeNonBlocking(client_fd);

                epoll_event client_event;
                memset(&client_event, 0, sizeof(client_event));
                client_event.events = EPOLLIN | EPOLLET; // Edge-triggered
                client_event.data.fd = client_fd;

                if (epoll_ctl(_epollFD, EPOLL_CTL_ADD, client_fd, &client_event) == -1)
                {
                    perror("epoll_ctl: client_fd");
                    close(client_fd);
                    continue;
                }

                // Créer utilisateur et initialiser état
                User* newUser = new User();
                _users[client_fd] = newUser;
                _userStates[client_fd] = WAIT_NICK;

                const char* askNick = "Welcome! Please enter your nick name:\n";
                write(client_fd, askNick, strlen(askNick));
            }
            else if (event_fd == STDIN_FILENO)
            {
                // Commandes serveur stdin
                string input;
                getline(cin, input);
                if (input == "quit")
                {
                    cout << "Shutting down server." << endl;
                    _running = false;
                    break;
                }
                else
                {
                    cout << "[Server command] " << input << endl;
                }
            }
            else
            {
                // Données client
                memset(_buffer, 0, IRC_MESSAGE_MAX);
                int count = read(event_fd, _buffer, IRC_MESSAGE_MAX);
                if (count <= 0)
                {
                    cout << "Client disconnected: FD = " << event_fd << endl;
                    close(event_fd);
                    epoll_ctl(_epollFD, EPOLL_CTL_DEL, event_fd, NULL);
                    delete _users[event_fd];
                    _users.erase(event_fd);
                    _userStates.erase(event_fd);
                    _tempNick.erase(event_fd);
                }
                else
                {
                    string input(_buffer, count);

                    if (_userStates[event_fd] == WAIT_NICK)
                    {
                        if (!input.empty())
                        {
                            _tempNick[event_fd] = input;
                            const char* askUser = "Please enter your user name:\n";
                            write(event_fd, askUser, strlen(askUser));
                            _userStates[event_fd] = WAIT_USER;
                        }
                        else
                        {
                            const char* askNick = "Please enter your nick name:\n";
                            write(event_fd, askNick, strlen(askNick));
                        }
                    }
                    else if (_userStates[event_fd] == WAIT_USER)
                    {
                        if (!input.empty())
                        {
                            _users[event_fd]->setNickName(_tempNick[event_fd]);
                            _users[event_fd]->setUserName(input);

                            const char* welcomeComplete = "Registration complete. Welcome!\n";
                            write(event_fd, welcomeComplete, strlen(welcomeComplete));

                            cout << "New client registered: FD = " << event_fd
                                      << ", nick = " << _tempNick[event_fd]
                                      << ", user = " << input << endl;

                            _userStates[event_fd] = REGISTERED;
                            _tempNick.erase(event_fd);
                        }
                        else
                        {
                            const char* askUser = "Please enter your user name:\n";
                            write(event_fd, askUser, strlen(askUser));
                        }
                    }
                    else
                    {
                        // Client déjà enregistré : gérer les commandes/messages ici
                        cout << "Received from client " << event_fd << ": " << input << endl;

                        // Exemple : echo simple
                        write(event_fd, input.c_str(), input.length());
                    }
                }
            }
        }
    }

    // Cleanup
    close(_epollFD);
    close(_serverFd);
}
