/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:13:07 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/27 14:48:00 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DOG_HPP_
# define _DOG_HPP_

# include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog( void );
        ~Dog();
        Dog( Dog const& copy );
        Dog& operator=( const Dog& other );

        void makeSound( void ) const;
        std::string getType( void ) const;
};

#endif