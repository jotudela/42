#pragma once

#include "libs.hpp"
#include "Admin.hpp"

class Server
{
    private:

        int _port;
        int _serverFd;
        int _epollFD;
        std::string _passWord;
        bool _running;
        Admin _admin;

        struct sockaddr_in _serverAddr;
        struct epoll_event _events[MAX_EVENTS];
        char _buffer[BUFFER_SIZE];

        Server( const Server & );
        Server& operator=( const Server & );

    public:

        Server( int port, std::string passWord );
        ~Server();

        const std::string& getPassWord() const;
        int getPort() const;

        const std::string& getAdminNickName() const;
        const std::string& getAdminUserName() const;
        const std::string& getStaffNickName() const;
        const std::string& getStaffUserName() const;

        void run();
};