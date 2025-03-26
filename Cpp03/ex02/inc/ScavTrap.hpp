/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:45:51 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/26 14:42:07 by jotudela         ###   ########.fr       */
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
        virtual~ScavTrap();
        ScavTrap( ScavTrap const& copy );
        ScavTrap& operator=( const ScavTrap& other );

        //Ohter functions
        virtual void guardGate();
        int getAttacksDamage( void );
        void printStats( void );
};

#endif