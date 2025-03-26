/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:28:23 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/26 14:44:49 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRAGTRAP_HPP_
# define _FRAGTRAP_HPP_

# include "../inc/ScavTrap.hpp"

class FragTrap : public ScavTrap
{
    public:

        //Basic functions
        FragTrap( std::string n );
        ~FragTrap();
        FragTrap( FragTrap const& copy );
        FragTrap& operator=( const FragTrap& other );

        //Other functions
        void hightFivesGuys( void );
};

#endif