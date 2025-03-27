/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:30:05 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/27 16:23:16 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

using std::string;
using std::cout;
using std::endl;

Cat::Cat( void ) : Animal("Cat"), brain(new Brain())
{
    cout << "This animal is a " << type << "." << endl;
}

Cat::~Cat()
{
    delete brain;
    cout << "This " << type << " has been destroyed !" << endl;
}

Cat& Cat::operator=( const Cat& other ) {
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

Cat::Cat( Cat const& copy ) : Animal(copy), brain(NULL)
{
    cout << "Copy constructor for Cat called" << endl;
    cout << "copy.brain = " << copy.brain << endl; // 🔍 Debug
    
    if (copy.brain) {
        brain = new Brain(*copy.brain);
        cout << "Brain copied successfully!" << endl;
    } else {
        cout << "Warning: copy.brain is nullptr!" << endl;
    }
}

void Cat::makeSound( void ) const
{
    cout << "Mew mewmew mewmew MEW !" << endl;
}

string Cat::getType( void ) const
{
    return type;
}

Brain* Cat::getBrain() const
{
    return brain;
}