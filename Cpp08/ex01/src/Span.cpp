#include "../inc/Span.hpp"

Span::Span() : _N(0){}

Span::Span( unsigned int N ) : _N(N){}

Span::~Span(){}

Span::Span( const Span& copy ) : _N(copy._N), _tab(copy._tab){}

Span& Span::operator=( const Span& other )
{
    if (this != &other)
    {
        this->_N = other._N;
        this->_tab = other._tab;
    }
    return *this;
}

void Span::addNumber( int nb )
{
    if (_tab.size() == _N)
        throw MaxNumbers();
    _tab.push_back(nb);
    std::sort(_tab.begin(), _tab.end());
}

int Span::shortestSpan( void ) const
{
    if (_tab.size() == 0)
        throw CantReturnSpan1();
    else if (_tab.size() == 1)
        throw CantReturnSpan2();
    int minDiff = _tab[1] - _tab[0];
    for (std::size_t i = 1; i < _tab.size() - 1; ++i)
    {
        int diff = _tab[i + 1] - _tab[i];
        if (diff < minDiff)
            minDiff = diff;
    }
    return minDiff;
}

int Span::longestSpan( void ) const
{
    if (_tab.size() == 0)
        throw CantReturnSpan1();
    else if (_tab.size() == 1)
        throw CantReturnSpan2();
    return _tab.back() - _tab.front();
}

void Span::addRandomNumbers( unsigned int count )
{
    if (_tab.size() + count > _N)
        throw MaxNumbers();

    static bool seeded = false;
    if (!seeded) {
        std::srand(static_cast<unsigned int>(std::time(NULL)));
        seeded = true;
    }

    std::vector<int> temp;
    temp.reserve(count);
    std::generate_n(std::back_inserter(temp), count, std::rand);
    _tab.insert(_tab.end(), temp.begin(), temp.end());
    std::sort(_tab.begin(), _tab.end());
}