/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 19:28:40 by jojo              #+#    #+#             */
/*   Updated: 2025/03/26 19:45:57 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

using std::string;
using std::cout;
using std::endl;

FragTrap::FragTrap( string n ): ClapTrap(n)
{
    this->health = 100;
    this->energy = 100;
    this->damage = 30;
    cout << "FragTrap " << name << " has been created !" << endl;
}

FragTrap::~FragTrap()
{
    cout << "FragTrap " << this->name << " has been destroyed !" << endl;
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

FragTrap::FragTrap( FragTrap const& copy ): ClapTrap(copy)
{
    this->health = copy.health;
    this->energy = copy.energy;
    this->damage = copy.damage;
    cout << "FragTrap copy constructor called for " << copy.name << endl; 
}

void FragTrap::highFivesGuys( void )
{
    cout << "FragTrap " << this->name << " says: Give me a high five !" << endl;
}

void FragTrap::attack( const string& target )
{
    if (this->energy <= 0){
        cout << "FragTrap " << this->name << " has no energy to do anythings !" << endl;
        return ;
    }
    if (this->health <= 0){
        cout << "FragTrap " << this->name << " has no health !" << endl;
        return ;
    }
    this->energy -= 1;
    cout << "FragTrap "
        << this->name
        << " attacks "
        << target
        << ", causing "
        << this->damage
        << " points of damage !" << endl;
}

int FragTrap::getAttacksDamage( void ) const { return this->damage; }

void FragTrap::printStats( void )
{
    cout << "FragTrap "
        << this->name << endl
        << "Health: "
        << this->health << endl
        << "Energy points: "
        << this->energy << endl
        << "Attacks damage: "
        << this->damage << endl;
}