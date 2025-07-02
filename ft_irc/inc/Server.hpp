#pragma once

#include "libs.hpp"
#include "Admin.hpp"
#include "User.hpp"

enum InputState { WAIT_NICK = 0, WAIT_USER = 1, REGISTERED = 2, WAIT_PASSWORD = 3, JOINED = 4 };

class Server
{
    private:

        int _port;
        int _serverFd;
        int _epollFD;
        int _opt;
        std::string _topic;
        std::string _passWord;

        bool _running;
        bool _invite;

        Admin _admin;
        std::map<int, Admin *> _staffs;
        std::map<int, int> _staffStates;
        std::map<int, User *> _users;
        std::map<int, int> _userStates;
        std::map<int, std::string> _tempNick;
        std::map<int, std::string> _tempUser;

        struct sockaddr_in _serverAddr;
        struct epoll_event _events[MAX_EVENTS];
        char _buffer[IRC_MESSAGE_MAX];

        Server( const Server & );
        Server& operator=( const Server & );

    public:

        Server( int port, std::string passWord );
        ~Server();

        const std::string& getPassWord() const;
        const std::string& getTopic() const;
        int getPort() const;

        const std::string& getAdminNickName() const;
        const std::string& getAdminUserName() const;
        const std::string& getStaffNickName() const;
        const std::string& getStaffUserName() const;

        void makeNonBlocking(int fd);
        void setUpServer();

        void run();
        void freeData();
        int createNewUser();
        int commandAdminStaff();
        int commandUser( int event_fd );
        int userToStaff( int fd );
        int staffToUser( int fd );
};