#pragma once

#include "libs.hpp"

class Server
{
    private:

        int port;
        int serverFd;
        int epollFD;
        std::string passWord;
        struct sockaddr_in serverAddr;

        Server( const Server & );
        Server& operator=( const Server & );

    public:

        Server( int port, std::string passWord );
        ~Server();

        const std::string& getPassWord() const;
        const int& getPort() const;
};