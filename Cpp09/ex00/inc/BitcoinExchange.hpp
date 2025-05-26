#ifndef _BITCOINEXCHANGE_HPP_
# define _BITCOINEXCHANGE_HPP_

# include <iostream>
# include <map>
# include <iterator>
# include <fstream>
# include <sstream>
# include <string>
# include <cstdlib>
# include <cctype>
# include <limits>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _data;

        bool isValidDate(const std::string& date) const;
        bool isValidValue(const std::string& valueStr) const;
        bool isValidInputLine(const std::string& line, std::string& date, std::string& value) const;
        float getClosestRate(const std::string& date) const;

    public:

        //Basic functions
        BitcoinExchange();
        BitcoinExchange( const std::string& filename );
        ~BitcoinExchange();
        BitcoinExchange( const BitcoinExchange& copy );
        BitcoinExchange& operator=( const BitcoinExchange& other );

        void getData( std::ifstream& file );
        void printConversions(const std::string& inputFilename) const;
};

#endif