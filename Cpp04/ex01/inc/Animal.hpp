/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:03:18 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/27 15:30:51 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ANIMAL_HPP_
# define _ANIMAL_HPP_

# include <iostream>
# include <string>
# include <iomanip>
# include <cstdlib>
# include <limits>
# include <sstream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal( std::string n );
        virtual ~Animal();
        Animal( Animal const& copy );
        virtual Animal& operator=( const Animal& other );

        virtual void makeSound( void ) const;
        std::string getType( void ) const;
};

#endif