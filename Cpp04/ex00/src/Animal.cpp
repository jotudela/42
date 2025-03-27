/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:11:56 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/27 15:12:42 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

using std::string;
using std::cout;
using std::endl;

Animal::Animal(){}

Animal::Animal( string n ): type(n)
{
    cout << "This animal is a " << type << "." << endl;
}

Animal::~Animal()
{
    if (type.empty())
        cout << "This animal with no type has been destroyed !" << endl;
    else
        cout << "This animal has been destroyed !" << endl;
}

Animal& Animal::operator=( const Animal& other )
{
    if (this != &other) {
        if (this->type.empty())
            cout << "This animal has no type and is now " << other.type << " !" << endl;
        else
            cout << "This animal name " << this->type << " is now " << other.type << " !" << endl;
        this->type = other.type;
    }
    return *this;
}

Animal::Animal( Animal const& copy )
{
    cout << "Copy constructor called" << endl;
    *this = copy;
}

void Animal::makeSound( void ) const
{
    cout << "Some generic animal sound!" << endl;
}

string Animal::getType( void ) const
{
    return type;
}