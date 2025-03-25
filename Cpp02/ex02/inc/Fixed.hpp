/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:07:25 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/25 17:13:46 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_HPP_
# define _FIXED_HPP_

# include <iostream>
# include <string>
# include <iomanip>
# include <cstdlib>
# include <limits>
# include <sstream>
# include <cmath>

class Fixed
{
    private:
        int value;
        static const int fractionalBits = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed( Fixed const& copy );
        Fixed( const int raw );
        Fixed( const float raw );

        //Surchrage comparaison
        bool operator>( const Fixed& right );
        bool operator<( const Fixed& right );
        bool operator>=( const Fixed& right );
        bool operator<=( const Fixed& right );
        bool operator==( const Fixed& right );
        bool operator!=( const Fixed& right );
        
        //Surcharge assignation
        Fixed& operator=( const Fixed& other );

        //Surcharge arithmetique
        Fixed operator+( const Fixed& right );
        Fixed operator-( const Fixed& right );
        Fixed operator*( const Fixed& right );
        Fixed operator/( const Fixed& right );

        // Operateurs d'incrementation
        Fixed&	operator++( void );
        Fixed	operator++( int ) ;
        Fixed&	operator--( void );
        Fixed	operator--( int );

        // Static functions min and max
        static Fixed&		min( Fixed& nb1, Fixed& nb2);
        static const Fixed&	min( const Fixed& nb1, const Fixed& nb2);
        static Fixed&		max( Fixed& nb1, Fixed& nb2);
        static const Fixed&	max( const Fixed& nb1, const Fixed& nb2);
        
        //Ohter function
        int getRawBits( void ) const;
        void setRawBits( const int raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif