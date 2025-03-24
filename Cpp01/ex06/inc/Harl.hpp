/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:16:24 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/24 13:15:34 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HARL_HPP_
# define _HARL_HPP_

# include <iostream>
# include <string>
# include <iomanip>
# include <cstdlib>
# include <limits>
# include <sstream>

class Harl
{
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );

        void(Harl::*ptrDebug)( void );
        void(Harl::*ptrInfo)( void );
	    void(Harl::*ptrWarning)( void );
	    void(Harl::*ptrError)( void );
    public:
        Harl();
        ~Harl();
        void complain( std::string level );
};

#endif