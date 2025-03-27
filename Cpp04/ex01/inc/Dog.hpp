/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:13:07 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/27 16:01:08 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DOG_HPP_
# define _DOG_HPP_

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain* brain;
    public:
        Dog( void );
        ~Dog();
        Dog( Dog const& copy );
        Dog& operator=( const Dog& other );

        void makeSound( void ) const;
        std::string getType( void ) const;
        Brain* getBrain() const;
};

#endif