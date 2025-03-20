/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:24:54 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/20 13:37:29 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB( std::string n ): name(n){}

void HumanB::setWeapon( Weapon& new_wepon )
{
    b_weapon = new_wepon;
}

void HumanB::attack()
{
    std::cout << name << " attacks with their " << b_weapon.getType() << std::endl;
}
