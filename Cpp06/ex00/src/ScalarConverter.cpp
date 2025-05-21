#include "../inc/ScalarConverter.hpp"

using std::string;
using std::cout;
using std::endl;

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter( const ScalarConverter& ){}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter& ){
    return *this;
}

ScalarConverter::~ScalarConverter(){}

bool ScalarConverter::isChar( const std::string& str )
{
    return str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]);
}

bool ScalarConverter::isInt( const std::string& str )
{
    char* endptr = NULL;
    std::strtol(str.c_str(), &endptr, 10);
    return *endptr == '\0';
}

bool ScalarConverter::isFloat( const std::string& str )
{
    if (str == "-inff" || str == "+inff" || str == "nanf")
        return true;
    char* endptr = NULL;
    std::strtof(str.c_str(), &endptr);
    return *endptr == 'f' && *(endptr + 1) == '\0';
}

bool ScalarConverter::isDouble( const std::string& str )
{
    if (str == "-inf" || str == "+inf" || str == "nan")
        return true;
    char* endptr = NULL;
    std::strtod(str.c_str(), &endptr);
    return *endptr == '\0';
}

void ScalarConverter::fromChar( char c )
{
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::fromInt( int i )
{
    if (i >= 32 && i <= 126)
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void ScalarConverter::fromFloat( float f )
{
    if (std::isnan(f) || std::isinf(f))
        std::cout << "char: impossible" << std::endl;
    else if (f >= 32 && f <= 126)
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    if (std::isnan(f) || std::isinf(f) ||
        f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;

    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::fromDouble( double d  )
{
    if (std::isnan(d) || std::isinf(d))
        std::cout << "char: impossible" << std::endl;
    else if (d >= 32 && d <= 126)
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    if (std::isnan(d) || std::isinf(d) ||
        d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;

    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert( const string& literal )
{
    if (isChar(literal))
        fromChar(literal[0]);
    else if (isInt(literal))
        fromInt(std::atoi(literal.c_str()));
    else if (isFloat(literal))
        fromFloat(std::strtof(literal.c_str(), NULL));
    else if (isDouble(literal))
        fromDouble(std::strtod(literal.c_str(), NULL));
    else
        std::cout << "Conversion impossible: Unknown type" << std::endl;
}