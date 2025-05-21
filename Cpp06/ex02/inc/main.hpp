#ifndef _MAIN_HPP_
# define _MAIN_HPP_

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <cstdlib>
# include <ctime>
# include <exception>

Base* generate( void );
void identify( Base* p );
void identify( Base& p );

#endif