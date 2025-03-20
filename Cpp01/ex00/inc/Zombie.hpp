/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:36:04 by jojo              #+#    #+#             */
/*   Updated: 2025/03/19 11:17:09 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ZOMBIE_HPP_
# define _ZOMBIE_HPP_

# include <iostream>
# include <string>
# include <iomanip>
# include <cstdlib>
# include <limits>
# include <sstream>

class Zombie
{
    private:
        std::string name;
    public:
        Zombie(std::string n);
        ~Zombie();
        void announce( void );
        
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif