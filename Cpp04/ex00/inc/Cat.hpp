/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:28:40 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/27 14:48:13 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CAT_HPP_
# define _CAT_HPP_

# include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat( void );
        ~Cat();
        Cat( Cat const& copy );
        Cat& operator=( const Cat& other );

        void makeSound( void ) const;
        std::string getType( void ) const;
};

#endif