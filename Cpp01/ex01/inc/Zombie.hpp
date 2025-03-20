/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:36:04 by jojo              #+#    #+#             */
/*   Updated: 2025/03/20 09:42:42 by jotudela         ###   ########.fr       */
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
        Zombie();
        ~Zombie();
        void setName( std::string n );
        void announce( void );
        
};

Zombie* zombieHorde( int N, std::string name );

#endif