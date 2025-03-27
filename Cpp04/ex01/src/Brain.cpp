/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:27:13 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/27 16:26:12 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

using std::string;
using std::cout;
using std::endl;

Brain::Brain()
{
    cout << "Brain has been created !" << endl;
}

Brain::~Brain()
{
    cout << "Brain has been destroyed !" << endl;
}

Brain& Brain::operator=( const Brain& other )
{
    if (this != &other) {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
        cout << "Brain assignment operator called" << endl;
    }
    return *this;
}

Brain::Brain( Brain const& copy )
{
    *this = copy;
}

void Brain::setIdea( int index, const string& idea )
{
    if (index >= 0 && index < 100)
        ideas[index] = idea;
}

string Brain::getIdea( int index ) const
{
    if (index >= 0 && index < 100)
        return ideas[index];
    return "";
}