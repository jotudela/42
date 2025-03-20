/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:03:43 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/20 13:21:39 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HUMANA_HPP_
# define _HUMANA_HPP_

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon& a_weapon;
    public:
        HumanA( std::string n, Weapon& new_weapon );
        void attack();
};

#endif