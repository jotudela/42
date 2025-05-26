#ifndef _RPN_HPP_
# define _RPN_HPP_

# include <iostream>
# include <stack>
# include <sstream>

class RPN
{
    private:
        std::stack<int> _data;

    public:

        //Basic functions
        RPN();
        ~RPN();
        RPN( const RPN& copy );
        RPN& operator=( const RPN& other );

        //Evaluate
        int evaluateRPN( const std::string& expr );
};

#endif