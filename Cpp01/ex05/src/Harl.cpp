/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:31:13 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/24 13:43:00 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

void Harl::debug( void )
{
    std::cout << "I love potatos." << std::endl;
}

void Harl::info( void )
{
    std::cout << "My shoes is gray." << std::endl;
}

void Harl::warning( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::error( void )
{
    std::cout << "This is a error." << std::endl;
}

Harl::Harl()
{
    ptrDebug = &Harl::debug;
    ptrInfo = &Harl::info;
    ptrWarning = &Harl::warning;
    ptrError = &Harl::error;
}

Harl::~Harl(){}

void Harl::complain( std::string level )
{
    switch (level[0])
    {
        case 'D':
            (this->*ptrDebug)();
            break;
        case 'I':
            (this->*ptrInfo)();
            break;
        case 'W':
            (this->*ptrWarning)();
            break;
        case 'E':
            (this->*ptrError)();
            break;
        default:
            break;
    }
}
