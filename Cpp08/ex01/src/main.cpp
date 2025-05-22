#include "../inc/Span.hpp"

int main()
{
    try{
        Span sp = Span(5);
        try{
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        } catch( const Span::CantReturnSpan1& e ){
            std::cout << e.what() << std::endl;
        }
        try{
            sp.addNumber(6);
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        } catch( const Span::CantReturnSpan2& e ){
            std::cout << e.what() << std::endl;
        }
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        sp.addNumber(0);
    } catch( const Span::MaxNumbers& e ){
        std::cout << e.what() << std::endl;
    }
    try {
        Span sp(30000);

        sp.addRandomNumbers(30000);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}