/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:05:09 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/26 14:13:47 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

using std::string;
using std::cout;
using std::endl;

ScavTrap::ScavTrap( string n ): ClapTrap(n)
{
    cout << "ScavTrap " << name << " has been created !" << endl;
}

ScavTrap::~ScavTrap()
{
    cout << "ScavTrap " << this->name << " has been desroyed !" << endl;
}

ScavTrap& ScavTrap::operator=( const ScavTrap& other )
{
    if (this != &other){
        cout << "ScavTrap " << name << " is now " << other.name << " !" << endl;
        this->name = other.name;
        this->health = other.health;
        this->energy = other.energy;
        this->damage = other.damage;
    }
    return *this;
}

ScavTrap::ScavTrap( ScavTrap const& copy ): ClapTrap(copy)
{
    cout << "ScavTrap copy constructor called for " << copy.name << endl; 
}

void ScavTrap::guardGate()
{
    cout << "ScavTrap " << this->name << " is now on Guard keeper mod !" << endl;
}

int ScavTrap::getAttacksDamage( void ){ return this->damage; }

void ScavTrap::printStats( void )
{
    cout << "ScavTrap "
        << this->name << endl
        << "Health: "
        << this->health << endl
        << "Energy points: "
        << this->energy << endl
        << "Attacks damage: "
        << this->damage << endl;
}