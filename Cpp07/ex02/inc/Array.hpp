#ifndef _ARRAY_HPP_
# define _ARRAY_HPP_

# include <iostream>
# include <stdexcept>
# include <cstddef>

template <typename T>
class Array
{
    private:
        T* _data;
        std::size_t _size;
    
    public:

        //Basic functions
        Array() : _data(NULL), _size(0){}
        Array( std::size_t n ) : _data(new T[n]()), _size(n){}

        Array( const Array& copy ) : _data(new T[copy._size]), _size(copy._size){
            for (std::size_t i = 0; i < _size; i++)
                _data[i] = copy._data[i];
        }

        Array& operator=( const Array& other ){
            if (this != &other){
                delete[] _data;
                _size = other._size;
                _data = new T[_size];
                for (std::size_t i = 0; i < _size; i++)
                    _data[i] = other._data[i];
            }
            return *this;
        }

        ~Array() { delete[] _data; }

        //Exception
        class NotGoodIndex : public std::exception{
            public:
                virtual const char* what() const throw(){
                    return "Index is out of range";
                }
        };

        //Operator []
        T& operator[]( std::size_t index ){
            if (index >= _size)
                throw NotGoodIndex();
            return _data[index];
        }

        //Return size of _data
        std::size_t size() const{
            return _size;
        }
};

#endif