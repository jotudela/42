/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:18:45 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/27 16:23:07 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

using std::string;
using std::cout;
using std::endl;

Dog::Dog( void ) : Animal("Dog"), brain(new Brain())
{
    cout << "This animal is a " << type << "." << endl;
}

Dog::~Dog()
{
    delete brain;
    cout << "This " << type << " has been destroyed !" << endl;
}

Dog& Dog::operator=( const Dog& other ) {
    if (this != &other) {
        cout << "Assignation de " << other.type << " vers " << this->type << endl;
        cout << "other.brain = " << other.brain << endl; // 🔍 Debug

        Animal::operator=(other);

        if (brain) delete brain;
        brain = (other.brain) ? new Brain(*other.brain) : NULL;

        cout << "brain après assignation: " << brain << endl;
    }
    return *this;
}

Dog::Dog( Dog const& copy ) : Animal(copy), brain(NULL)
{
    cout << "Copy constructor for dog called" << endl;
    cout << "copy.brain = " << copy.brain << endl; // 🔍 Debug
    
    if (copy.brain) {
        brain = new Brain(*copy.brain);
        cout << "Brain copied successfully!" << endl;
    } else {
        cout << "Warning: copy.brain is nullptr!" << endl;
    }
}

void Dog::makeSound( void ) const
{
    cout << "WAFF WAFFF WAFF WAFF WAFFFFFFFF !" << endl;
}

string Dog::getType( void ) const
{
    return type;
}

Brain* Dog::getBrain() const
{
    return brain;
}