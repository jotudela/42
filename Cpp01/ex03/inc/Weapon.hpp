/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:25:23 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/24 09:13:46 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WEAPON_HPP_
# define _WEAPON_HPP_

# include <iostream>
# include <string>
# include <iomanip>
# include <cstdlib>
# include <limits>
# include <sstream>

class Weapon
{
    private:
        std::string weapon_type;
    public:
        Weapon( std::string n );
        ~Weapon();
        const std::string& getType();
        void setType( std::string new_weapon );
};

#endif