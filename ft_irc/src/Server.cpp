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