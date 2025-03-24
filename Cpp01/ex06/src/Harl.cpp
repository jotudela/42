/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:31:13 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/24 14:09:32 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

void Harl::debug( void )
{
    std::cout << "[ DEBUG ]" << std::endl
        << "I love potatos.\n" << std::endl;
}

void Harl::info( void )
{
    std::cout << "[ INFO ]" << std::endl
        << "My shoes is gray.\n" << std::endl;
}

void Harl::warning( void )
{
    std::cout << "[ WARNING ]" << std::endl
        << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::error( void )
{
    std::cout << "[ ERROR ]" << std::endl
        << "This is a error.\n" << std::endl;
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
        case 'I':
            (this->*ptrInfo)();
        case 'W':
            (this->*ptrWarning)();
        case 'E':
            (this->*ptrError)();
        default:
            break;
    }
}
