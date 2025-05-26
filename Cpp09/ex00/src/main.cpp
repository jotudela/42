#include "../inc/BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2){
        std::cerr << "Error: good format is './btc filename'" << std::endl;
        return 1;
    }
    BitcoinExchange data("data.csv");

    std::string inputFile = av[1];
    data.printConversions(inputFile);
    return 0;
}