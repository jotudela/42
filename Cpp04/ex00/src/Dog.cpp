/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:18:45 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/27 14:57:07 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

using std::string;
using std::cout;
using std::endl;

Dog::Dog( void ) : Animal()
{
    type = "Dog";
    cout << "This animal is a " << type << "." << endl;
}

Dog::~Dog()
{
    cout << "This " << type << " has been destroyed !" << endl;
}

Dog& Dog::operator=( const Dog& other )
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

Dog::Dog( Dog const& copy ) : Animal(copy)
{
    cout << "Copy constructor called" << endl;
    *this = copy;
}

void Dog::makeSound( void ) const
{
    cout << "WAFF WAFFF WAFF WAFF WAFFFFFFFF !" << endl;
}

string Dog::getType( void ) const
{
    return type;
}