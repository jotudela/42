/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:23:47 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/24 09:23:24 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HUMANB_HPP_
# define _HUMANB_HPP_

#include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon* b_weapon;
    public:
        HumanB( std::string n );
        void setWeapon( Weapon& new_wepon );
        void attack();
};

#endif