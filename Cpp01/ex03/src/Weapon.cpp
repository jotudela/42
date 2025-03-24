/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:38:16 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/24 09:13:48 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"

Weapon::Weapon( std::string n )
{
    weapon_type = n;
}

Weapon::~Weapon()
{

}

const std::string& Weapon::getType()
{
    return weapon_type;
}

void Weapon::setType( std::string new_weapon )
{
    weapon_type = new_weapon;
}
