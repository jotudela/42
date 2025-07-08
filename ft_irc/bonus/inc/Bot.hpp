#pragma once

#include "libs.hpp"

class Bot
{
    private:

        std::time_t _start;
        std::time_t _last_display;
        std::time_t _now;

        Bot( const Bot & );
        Bot& operator=( const Bot & );

    public:

        Bot();
        ~Bot();

        void setStartTime();
        bool calculTime();
        void printInfoForUser( int fd, const std::string& heure ) const;
        void printInfoForAdminStaff() const;
};