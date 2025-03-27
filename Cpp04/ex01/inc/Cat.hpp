/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:28:40 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/27 16:01:43 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CAT_HPP_
# define _CAT_HPP_

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain* brain;
    public:
        Cat( void );
        ~Cat();
        Cat( Cat const& copy );
        Cat& operator=( const Cat& other );

        void makeSound( void ) const;
        std::string getType( void ) const;
        Brain* getBrain() const;
};

#endif