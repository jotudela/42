#ifndef _SCALARCONVERTER_HPP_
# define _SCALARCONVERTER_HPP_

# include <string>
# include <iostream>
# include <limits>
# include <iomanip>
# include <sstream>
# include <cmath>
# include <cstdlib>
# include <cctype>
# include <limits.h>

class ScalarConverter
{
    private:
        // Constructeur privé pour empêcher l'instanciation
        ScalarConverter();
        ScalarConverter( const ScalarConverter& );
        ScalarConverter& operator=( const ScalarConverter& );
        ~ScalarConverter();

        // Méthodes internes pour chaque type
        static void fromChar( char c );
        static void fromInt( int i );
        static void fromFloat( float f );
        static void fromDouble( double d );

        // Méthodes pour détecter le type de la chaîne d'entrée
        static bool isChar( const std::string& str );
        static bool isInt( const std::string& str );
        static bool isFloat( const std::string& str );
        static bool isDouble( const std::string& str );
    
    public:
        // Méthode statique principale à appeler depuis le main
        static void convert( const std::string& literal );
};

#endif