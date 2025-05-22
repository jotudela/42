#ifndef _ITER_HPP_
# define _ITER_HPP_

# include <iostream>


template <typename T>
void basicFunction( T& a )
{
    (void)a;
}

template <>
void basicFunction<int>( int& a )
{
    std::cout << a << std::endl;

    a++;

    std::cout << a << std::endl;
}

template <>
void basicFunction<std::string>( std::string &a )
{
    std::cout << a << std::endl;

    a[0] = '_';

    std::cout << a << std::endl;
}

template <>
void basicFunction<float>( float& a )
{
    std::cout << a << std::endl;

    a -= 0.1f;

    std::cout << a << std::endl;
}

template <>
void basicFunction<double>( double& a )
{
    std::cout << a << std::endl;

    a += 0.1;

    std::cout << a << std::endl;
}

template <typename T>
void basicFunction2( const T& a )
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