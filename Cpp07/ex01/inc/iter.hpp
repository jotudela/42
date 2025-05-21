#ifndef _ITER_HPP_
# define _ITER_HPP_

# include <iostream>

template <typename T>
void print( const T& a )
{
    std::cout << a << std::endl;
}

template <typename T>
void iter( T* array, int lenght, void (*func)(const T&) )
{
    for (int i = 0; i < lenght; i++)
        func( array[i] );
}

template <typename T>
void iter( T* array, int lenght, void (*func)(T&) )
{
    for (int i = 0; i < lenght; i++)
        func( array[i] );
}

#endif