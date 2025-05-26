#include "../inc/RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const RPN& other) {
    _data = other._data;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other)
        _data = other._data;
    return *this;
}

int RPN::evaluateRPN(const std::string& expr)
{
    std::istringstream iss(expr);
    std::string token;

    while (iss >> token)
    {
        if (token.size() == 1 && isdigit(token[0]))
            _data.push(token[0] - '0');
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (_data.size() < 2){
                std::cerr << "Error: Not enough operands" << std::endl;
                return -1;
            }

            int b = _data.top();
            _data.pop();
            int a = _data.top();
            _data.pop();

            int res;
            if (token == "+")
                res = a + b;
            else if (token == "-")
                res = a - b;
            else if (token == "*")
                res = a * b;
            else {
                if (b == 0){
                std::cerr << "Error: Division by zero" << std::endl;
                return -1;
            }
                res = a / b;
            }
            _data.push(res);
        }
        else{
            std::cerr << "Error: Invalid token" << std::endl;
            return -1;
        }
    }

    if (_data.size() != 1){
        std::cerr << "Error: Invalid expression" << std::endl;
        return -1;
    }

    return _data.top();
}