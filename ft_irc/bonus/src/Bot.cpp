#include "Bot.hpp"

using std::string;
using std::cout;
using std::endl;
using std::cerr;

Bot::Bot(){}

Bot::~Bot(){}

void Bot::setStartTime()
{
    _start = std::time(0);
    _last_display = _start;
}

bool Bot::calculTime()
{
    _now = std::time(0);

    if (_now - _last_display >= 30)
    {
        _last_display = _now;
        return true;
    }
    return false;
}

void Bot::printInfoForUser( int fd, const string& heure ) const
{
    write(fd, "Hello ", 7);
    write(fd, heure.c_str(), heure.length());
    write(fd, ".\n", 2);
}