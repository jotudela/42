#include "../inc/Serializer.hpp"

int main()
{
    Data* ptr = new Data;
    uintptr_t raw = Serializer::serialize(ptr);
    Data* tmp = Serializer::deserialize(raw);

    std::cout << "Adress of ptr : " << ptr << "." << std::endl;
    std::cout << "Value of raw : " << raw << "." << std::endl;
    std::cout << "Adress of tmp : " << tmp << "." << std::endl;
    delete ptr;
}