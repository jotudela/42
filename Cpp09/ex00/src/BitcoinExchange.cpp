#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange( const std::string& filename )
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()){
        std::cerr << "Error: could not open file." << std::endl;
        return ;
    }
    getData(file);
    file.close();
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& copy ) : _data(copy._data){}

BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& other )
{
    if (this != &other)
        _data = other._data;
    return *this;
}

void BitcoinExchange::getData( std::ifstream& file )
{
        std::string line;
        std::getline(file, line);
        while (std::getline(file, line)) {
            if (line.empty())
                continue;

            std::stringstream ss(line);
            std::string date, value;

            if (!std::getline(ss, date, ',') || !std::getline(ss, value))
                continue;

            float rate = std::atof(value.c_str());

            _data[date] = rate;
    }
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;
    }

    int year, month, day;
    std::istringstream iss(date.substr(0, 4) + " " + date.substr(5, 2) + " " + date.substr(8, 2));
    if (!(iss >> year >> month >> day)) {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;
    }

    if (year < 2009 || year > 2025 || month < 1 || month > 12 || day < 1 || day > 31) {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;
    }

    static const int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (day > daysInMonth[month - 1]) {
        if (!(month == 2 && day == 29 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))) {
            std::cerr << "Error: bad input => " << date << std::endl;
            return false;
        }
    }

    return true;
}

std::string trim(const std::string& s)
{
    const std::string whitespace = " \t\n\r\f\v";
    size_t start = s.find_first_not_of(whitespace);
    if (start == std::string::npos)
        return "";
    size_t end = s.find_last_not_of(whitespace);
    return s.substr(start, end - start + 1);
}

bool BitcoinExchange::isValidValue(const std::string& valueStr) const
{
    std::string str = trim(valueStr);

    if (str.empty()) {
        std::cerr << "Error: bad input => '" << valueStr << "'" << std::endl;
        return false;
    }

    char* end = NULL;
    double value = std::strtod(str.c_str(), &end);

    if (end == str || *end != '\0') {
        std::cerr << "Error: bad input => '" << valueStr << "'" << std::endl;
        return false;
    }

    if (value < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }

    if (value > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }

    return true;
}

bool BitcoinExchange::isValidInputLine(const std::string& line, std::string& date, std::string& value) const
{
    size_t pipePos = line.find(" | ");
    if (pipePos == std::string::npos) {
        std::cerr << "Error: bad input => " << line << std::endl;
        return false;
    }

    date = trim(line.substr(0, pipePos));
    value = trim(line.substr(pipePos + 3));

    if (date.empty() || value.empty()) {
        std::cerr << "Error: bad input => " << line << std::endl;
        return false;
    }

    if (!isValidDate(date))
        return false;

    if (!isValidValue(value))
        return false;

    return true;
}

float BitcoinExchange::getClosestRate(const std::string& date) const
{
    std::map<std::string, float>::const_iterator it = _data.lower_bound(date);
    
    if (it != _data.end() && it->first == date)
        return it->second;

    if (it == _data.begin())
        return 0.0f;

    --it;
    return it->second;
}

void BitcoinExchange::printConversions(const std::string& inputFilename) const
{
    std::ifstream inputFile(inputFilename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(inputFile, line);

    while (std::getline(inputFile, line)) {
        std::string date, valueStr;

        if (!isValidInputLine(line, date, valueStr))
            continue;

        double value = std::strtod(valueStr.c_str(), NULL);
        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        float rate = getClosestRate(date);
        double result = value * rate;

        std::cout << date << " => " << value << " = " << result << std::endl;
    }

    inputFile.close();
}