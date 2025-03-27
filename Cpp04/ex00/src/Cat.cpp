/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:30:05 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/27 14:54:23 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

using std::string;
using std::cout;
using std::endl;

Cat::Cat( void ) : Animal()
{
    type = "Cat";
    cout << "This animal is a " << type << "." << endl;
}

Cat::~Cat()
{
    cout << "This " << type << " has been destroyed !" << endl;
}

Cat& Cat::operator=( const Cat& other )
{
    if (this != &other) {
        if (this->type.empty())
            cout << "This animal has no type and is now a " << other.type << " !" << endl;
        else
            cout << "This animal type " << this->type << " is now " << other.type << " !" << endl;
        this->type = other.type;
    }
    return *this;
}

Cat::Cat( Cat const& copy ) : Animal(copy)
{
    cout << "Copy constructor called" << endl;
    *this = copy;
}

void Cat::makeSound( void ) const
{
    cout << "Mew mewmew mewmew MEW !" << endl;
}

string Cat::getType( void ) const
{
    return type;
}