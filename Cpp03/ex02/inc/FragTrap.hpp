/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 19:13:04 by jojo              #+#    #+#             */
/*   Updated: 2025/03/26 19:36:32 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRAGTRAP_HPP_
# define _FRAGTRAP_HPP_

# include "../inc/ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:

        //Basic functions
        FragTrap( std::string n );
        ~FragTrap();
        FragTrap( FragTrap const& copy );
        FragTrap& operator=( const FragTrap& other );

        //Ohter functions
        void highFivesGuys( void );
        void attack( const std::string& target );
        int getAttacksDamage( void ) const;
        void printStats( void );
};

#endif