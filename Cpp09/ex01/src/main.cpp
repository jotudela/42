#include "../inc/RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: good format is './RPN '8 9 * 9 - 9 - 9 - 4 - 1 +''" << std::endl;
        return 1;
    }
    std::string expression(av[1]);
    RPN cal;
    int value = cal.evaluateRPN(expression);
    if (value == -1)
        return 1;
    std::cout << value << std::endl;
}