#ifndef _SERIALIZER_HPP_
# define _SERIALIZER_HPP_

# include <iostream>
# include <stdint.h>

typedef struct s_data
{
    int x;
}           Data;

class Serializer
{
    private:
        Serializer();
        Serializer( const Serializer& );
        Serializer& operator=( const Serializer& );
        ~Serializer();
    public:
        static uintptr_t serialize( Data* ptr );
        static Data* deserialize( uintptr_t raw );
};

#endif