/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:45:51 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/26 18:12:15 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SCAVTRAP_HPP_
# define _SCAVTRAP_HPP_

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:

        //Basic functions
        ScavTrap( std::string n );
        ~ScavTrap();
        ScavTrap( ScavTrap const& copy );
        ScavTrap& operator=( const ScavTrap& other );

        //Ohter functions
        void guardGate();
        void attack( const std::string& target );
        int getAttacksDamage( void ) const;
        void printStats( void );
};

#endif