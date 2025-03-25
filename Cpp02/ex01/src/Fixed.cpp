/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:27:08 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/25 16:34:54 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

using std::cout;
using std::endl;
using std::ostream;

Fixed::Fixed(): value(0)
{
    cout << "Default constructor called" << endl;
}

Fixed::Fixed( Fixed const& copy )
{
    cout << "Copy constructor called" << endl;
    *this = copy;
}

Fixed::Fixed( const int raw )
{
    cout << "Int constructor called" << endl;
    value = raw << fractionalBits;
}

Fixed::Fixed( const float raw )
{
    cout << "Float constructor called" << endl;
    value = roundf(raw * (1 << fractionalBits));
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
    return value;
}

void Fixed::setRawBits( int const raw )
{
    this->value = raw;
}

float Fixed::toFloat( void ) const
{
    return (float)value / (1 << fractionalBits);
}

int Fixed::toInt( void ) const
{
    return value >> fractionalBits;
}

ostream &operator<<(ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}