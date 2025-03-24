/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:24:54 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/24 09:28:58 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB( std::string n ): name(n), b_weapon(NULL){}

void HumanB::setWeapon( Weapon& new_wepon )
{
    b_weapon = &new_wepon;
}

void HumanB::attack()
{
    std::cout << name << " attacks with their " << b_weapon->getType() << std::endl;
}
