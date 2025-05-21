#ifndef _WHATEVER_HPP_
# define _WHATEVER_HPP_

# include <iostream>

template <typename T>
void swap( T& a, T& b )
{
    T c = a;
    a = b;
    b = c;
}

template <typename T>
const T& min( const T& a, const T& b )
{
    if (a < b)
        return a;
    return b;
}

template <typename T>
const T& max( const T& a, const T& b )
{
    if (a > b)
        return a;
    return b;
}

#endif