/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:08:22 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/20 13:23:20 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"

HumanA::HumanA(std::string n, Weapon& new_weapon) : name(n), a_weapon(new_weapon){}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << a_weapon.getType() << std::endl;
}
