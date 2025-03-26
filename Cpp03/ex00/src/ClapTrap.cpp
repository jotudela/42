/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:11:56 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/26 18:26:13 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

using std::string;
using std::cout;
using std::endl;

ClapTrap::ClapTrap( string n ): name(n), health(10), energy(10), damage(0)
{
    cout << "ClapTrap " << name << " has created !" << endl;
}

ClapTrap::~ClapTrap()
{
    cout << "ClapTrap " << name << " has destroyed !" << endl;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& other )
{
    if (this != &other){
        this->name = other.name;
        this->health = other.health;
        this->energy = other.energy;
        this->damage = other.damage;
        cout << "ClapTrap " << this->name << " is now " << other.name << " !" << endl;
    }
    return *this;
}

ClapTrap::ClapTrap( ClapTrap const& copy )
{
    cout << "Copy constructor called" << endl;
    *this = copy;
}

void ClapTrap::attack( const string& target )
{
    if (this->damage == 0){
        cout << "ClapTrap " << this->name << " can't do damage !" << endl;
        return ;
    }
    if (this->energy <= 0){
        cout << "ClapTrap " << this->name << " has no energy to do anythings !" << endl;
        return ;
    }
    if (this->health <= 0){
        cout << "ClapTrap " << this->name << " has no health !" << endl;
        return ;
    }
    this->energy -= 1;
    cout << "ClapTrap "
        << this->name
        << " attacks "
        << target
        << ", causing "
        << this->damage
        << " points of damage !" << endl;
}

void ClapTrap::takeDamage( unsigned int amount )
{
    if (this->health <= 0){
        cout << "ClapTrap " << this->name << " has no Health !" << endl;
        return ;
    }
    cout << "ClapTrap "
        << this->name
        << " take "
        << amount
        << " damage, now he have "
        << this->health
        << " Health !" <<endl;
}

void ClapTrap::beRepaired( unsigned int amount )
{
    if (this->energy <= 0){
        cout << "ClapTrap " << this->name << " has no energy to do anythings !" << endl;
        return ;
    }
    if (this->health <= 0){
        cout << "ClapTrap " << this->name << " has no health !" << endl;
        return ;
    }
    if (this->health == 10){
        cout << "ClapTrap " << this->name << " has max Health !" << endl;
        return ;
    }
    this->energy -= 1;
    cout << "ClapTrap "
        << this->name
        << "repaire him "
        << amount
        << " health, now he have "
        << this->health
        << " Health !" << endl;
}