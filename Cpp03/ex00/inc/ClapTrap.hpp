/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:03:18 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/26 10:29:40 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CLAPTRAP_HPP_
# define _CLAPTRAP_HPP_

# include <iostream>
# include <string>
# include <iomanip>
# include <cstdlib>
# include <limits>
# include <sstream>

class ClapTrap
{
    private:
        std::string name;
        int health;
        int energy;
        int damage;
    public:
    
        //Basic functions
        ClapTrap( std::string n );
        ~ClapTrap();
        ClapTrap( ClapTrap const& copy );
        ClapTrap& operator=( const ClapTrap& other );

        //Other functions
        void attack( const std::string& target );
        void takeDamage( unsigned int amount );
        void beRepaired( unsigned int amount );
};

#endif