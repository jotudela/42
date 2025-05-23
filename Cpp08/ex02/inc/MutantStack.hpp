#ifndef _MUTANTSTACK_HPP_
# define _MUTANTSTACK_HPP_

# include <iostream>
# include <list>
# include <stack>
# include <algorithm>
# include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:

        //Basic functions
        MutantStack(){}
        MutantStack( const MutantStack& copy ) : std::stack<T>(copy){}
        MutantStack& operator=( const MutantStack& other ){
            if (this != &other)
                std::stack<T>::operator=(other);
            return *this;
        }
        ~MutantStack(){}

        //Iterators
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }
        const_iterator begin() const { return this->c.begin(); }
        const_iterator end() const { return this->c.end(); }
};

#endif