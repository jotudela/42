#include "../inc/Server.hpp"

using std::string;
using std::cout;
using std::endl;

Server::Server( int port, string passWord ) : port(port), passWord(passWord){}

Server::~Server(){}

const string& Server::getPassWord() const
{
    return passWord;
}

const int& Server::getPort() const
{
    return port;
}