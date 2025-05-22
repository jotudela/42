#ifndef _SPAN_HPP_
# define _SPAN_HPP_

# include <vector>
# include <algorithm>
# include <iterator>
# include <iostream>
# include <cstdlib>
# include <ctime>

class Span
{
    private:
        unsigned int _N;
        std::vector<int> _tab;

    public:

        //Basic functions
        Span();
        Span( unsigned int N );
        ~Span();
        Span( const Span& copy );
        Span& operator=( const Span& other );

        void addNumber( int nb );
        int shortestSpan( void ) const;
        int longestSpan( void ) const;
        void addRandomNumbers( unsigned int count );

        class MaxNumbers : public std::exception{
            public:
                virtual const char* what() const throw(){
                    return "Max numbers strored reached, can't add more number.";
                }
        };

        class CantReturnSpan1 : public std::exception{
            public:
                virtual const char* what() const throw(){
                    return "There no numbers in vector !";
                }
        };

        class CantReturnSpan2 : public std::exception{
            public:
                virtual const char* what() const throw(){
                    return "There is only one number in vector !";
                }
        };
};

#endif