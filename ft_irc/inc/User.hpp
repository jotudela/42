#pragma once

#include "libs.hpp"

class User
{
    private:

        std::string _nickName;
        std::string _userName;

        User( const User & );
        User& operator=( const User & );

    public:

        User();
        ~User();

        const std::string& getNickName() const;
        const std::string& getUserName() const;

        void setNickName( const std::string& nickName );
        void setUserName( const std::string& userName );
};