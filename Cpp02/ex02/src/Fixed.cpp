/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:27:08 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/25 17:44:26 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

using std::cout;
using std::endl;
using std::ostream;

Fixed::Fixed(): value(0)
{

}

Fixed::Fixed( Fixed const& copy )
{;
    *this = copy;
}

Fixed::Fixed( const int raw )
{
    value = raw << fractionalBits;
}

Fixed::Fixed( const float raw )
{
    value = roundf(raw * (1 << fractionalBits));
}

Fixed::~Fixed()
{

}

Fixed& Fixed::operator=( const Fixed& other )
{
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

bool Fixed::operator>( const Fixed& right )
{
    return this->value > right.value;
}

bool Fixed::operator<( const Fixed& right )
{
    return this->value < right.value;
}

bool Fixed::operator>=( const Fixed& right )
{
    return this->value >= right.value;
}

bool Fixed::operator<=( const Fixed& right )
{
    return this->value <= right.value;
}

bool Fixed::operator==( const Fixed& right )
{
    return this->value == right.value;
}

bool Fixed::operator!=( const Fixed& right )
{
    return this->value != right.value;
}

Fixed Fixed::operator+( const Fixed& right )
{
    Fixed   f;

    f.value = this->value + right.value;
    return f;
}

Fixed Fixed::operator-( const Fixed& right )
{
    Fixed   f;

    f.value = this->value - right.value;
    return f;
}

Fixed Fixed::operator*( const Fixed& right )
{
    Fixed   f;

    f.value = (this->value * right.value) >> fractionalBits;
    return f;
}

Fixed Fixed::operator/( const Fixed& right )
{
    if (right.value == 0){
        cout << "Error: division by 0." << endl;
        return Fixed(0);
    }
    Fixed   f;

    f.value = (this->value << fractionalBits) / right.value;
    return f;
}

Fixed& Fixed::operator++( void )
{
    this->value++;
    return *this;
}

Fixed& Fixed::operator--( void )
{
    this->value--;
    return *this;
}

Fixed Fixed::operator++( int )
{
    Fixed   tmp = *this;

    this->value++;
    return tmp;
}

Fixed Fixed::operator--( int )
{
    Fixed   tmp = *this;

    this->value--;
    return tmp;
}

Fixed& Fixed::min( Fixed& nb1, Fixed& nb2 )
{
    return (nb1.value < nb2.value) ? nb1 : nb2;
}

const Fixed& Fixed::min( const Fixed& nb1, const Fixed& nb2 )
{
    return (nb1.value < nb2.value) ? nb1 : nb2;
}

Fixed& Fixed::max( Fixed& nb1, Fixed& nb2 )
{
    return (nb1.value > nb2.value) ? nb1 : nb2;
}

const Fixed& Fixed::max( const Fixed& nb1, const Fixed& nb2 )
{
    return (nb1.value > nb2.value) ? nb1 : nb2;
}