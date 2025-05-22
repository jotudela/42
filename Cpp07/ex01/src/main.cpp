#include "../inc/iter.hpp"

int main()
{
    int arrayInt[5] = {4, -9, 42, -12, 0};
    
    float arrayFloat[5] = {4.42f, -9.9f, 42.42f, -12.12f, 0.0f};

    std::string arrayString[5] = {"Heap is Better",
                            "Stack is Better",
                            "Elon Musk is Better",
                            "Jeff Bezos is better",
                            "Nutella is better with butter"};

    double arrayNope[5] = {4.33, -9.7, 42.2, -12.1, 0.9};
    
    const int arrayInt2[5] = {4, -9, 42, -12, 0};

    std::cout << "Array of int:\n" << std::endl;
    iter<int>(arrayInt, 5, *basicFunction<int>);
    std::cout << std::endl;

    std::cout << "Array of float:\n" << std::endl;
    iter<float>(arrayFloat, 5, *basicFunction<float>);
    std::cout << std::endl;

    std::cout << "Array of string:\n" << std::endl;
    iter<std::string>(arrayString, 5, *basicFunction<std::string>);
    std::cout << std::endl;

    std::cout << "Array of double:\n" << std::endl;
    iter<double>(arrayNope, 5, *basicFunction<double>);
    std::cout << std::endl;

    std::cout << "Array of const int:" << std::endl;
    iter(arrayInt2, 5, *basicFunction2<const int>);

    return 0;
}