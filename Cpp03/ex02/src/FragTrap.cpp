/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:46:50 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/26 15:15:24 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;

FragTrap::FragTrap( string n ): ScavTrap(n)
{
    cout << "FragTrap " << name << " has been created !" << endl;
}

FragTrap::~FragTrap()
{
    cout << "FragTrap " << name << " has been destroyed !" << endl;
}

FragTrap::FragTrap( FragTrap const& copy ): ScavTrap(copy)
{
    cout << "FragTrap copy constructor called for " << copy.name << endl;
}

FragTrap& FragTrap::operator=( const FragTrap& other )
{
    if (this != &other){
        cout << "FragTrap " << name << " is now " << other.name << " !" << endl;
        this->name = other.name;
        this->health = other.health;
        this->energy = other.energy;
        this->damage = other.damage;
    }
    return *this;
}

void FragTrap::hightFivesGuys( void )
{
    int reponse;
    std::cout << "Hey bro, do you want a high-five?!" << std::endl;
    std::cout << "yes(1) / no(2): ";
    std::cin >> reponse;

    switch (reponse) {
        case 1:
            std::cout << "You got a high-five, bro!" << std::endl;
            break;
        case 2:
            std::cout << "No high-five for you, maybe next time!" << std::endl;
            break;
        default:
            std::cout << "Invalid input, please enter 1 for yes or 2 for no." << std::endl;
            break;
    }
}
