#include "../inc/User.hpp"

using std::string;
using std::cout;
using std::endl;
using std::cin;

User::User() : _nickName(""), _userName(""){}

User::~User(){}

const string& User::getNickName() const
{
    return _nickName;
}

const string& User::getUserName() const
{
    return _userName;
}

void User::setNickName( const string& nickName )
{
    _nickName = nickName;
}

void User::setUserName( const string& userName )
{
    _userName = userName;
}