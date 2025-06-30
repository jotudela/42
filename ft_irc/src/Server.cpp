#include "../inc/Server.hpp"
#include "../inc/Admin.hpp"

using std::string;
using std::cout;
using std::endl;
using std::cin;

Server::Server( int port, string passWord ) : _port(port), _serverFd(-1),
_epollFD(-1), _passWord(passWord), _running(false)
{
    string nickName;
    string userName;

    _admin.setAdminStatus();

    cout << "Enter admin nick name : ";
    cin >> nickName;
    cout << endl << "Enter admin user name : ";
    cin >> userName;
    cout << endl;

    _admin.setAdminNames(nickName, userName);
}

Server::~Server(){}

const string& Server::getPassWord() const
{
    return _passWord;
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