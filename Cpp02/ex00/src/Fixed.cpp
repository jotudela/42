/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:27:08 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/25 12:55:15 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

using std::cout;
using std::endl;

Fixed::Fixed(): value(0)
{
    cout << "Default constructor called" << endl;
}

Fixed::Fixed( Fixed const& copy )
{
    cout << "Copy constructor called" << endl;
    *this = copy;
}

Fixed::~Fixed()
{
    cout << "Destructor called" << endl;
}

Fixed& Fixed::operator=( const Fixed& other )
{
    cout << "Copy assignment operator called" << endl;
    if (this != &other)
        this->value = other.getRawBits();
    return *this;
}

int Fixed::getRawBits( void ) const
{
    cout << "getRawBits member function called" << endl;
    return value;
}

void Fixed::setRawBits( int const raw )
{
    this->value = raw;
}
