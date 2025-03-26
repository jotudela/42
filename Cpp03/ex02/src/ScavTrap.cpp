/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:05:09 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/26 18:29:57 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

using std::string;
using std::cout;
using std::endl;

ScavTrap::ScavTrap( string n ): ClapTrap(n)
{
    this->health = 100;
    this->energy = 50;
    this->damage = 20;
    cout << "ScavTrap " << name << " has been created !" << endl;
}

ScavTrap::~ScavTrap()
{
    cout << "ScavTrap " << this->name << " has been destroyed !" << endl;
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
    this->health = copy.health;
    this->energy = copy.energy;
    this->damage = copy.damage;
    cout << "ScavTrap copy constructor called for " << copy.name << endl; 
}

void ScavTrap::guardGate()
{
    cout << "ScavTrap " << this->name << " is now in Gate Keeper mode!" << endl;
}

void ScavTrap::attack( const string& target )
{
    if (this->energy <= 0){
        cout << "ScavTrap " << this->name << " has no energy to do anythings !" << endl;
        return ;
    }
    if (this->health <= 0){
        cout << "ScavTrap " << this->name << " has no health !" << endl;
        return ;
    }
    this->energy -= 1;
    cout << "ScavTrap "
        << this->name
        << " attacks "
        << target
        << ", causing "
        << this->damage
        << " points of damage !" << endl;
}

int ScavTrap::getAttacksDamage( void ) const { return this->damage; }

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