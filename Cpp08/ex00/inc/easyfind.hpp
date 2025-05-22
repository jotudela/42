#ifndef _EASYFIND_HPP_
# define _EASYFIND_HPP_

# include <vector>
# include <list>
#include <deque>
# include <algorithm>
# include <iostream>

class NoNumber : public std::exception{
    public:
        virtual const char* what() const throw(){
            return "The number you passed in easyfind is not in data";
        }
};

template <typename T>
int& easyfind( T& data, int nb )
{
    typename T::iterator it = std::find(data.begin(), data.end(), nb);
    if (it == data.end())
        throw NoNumber();
    return *it;
}

#endif