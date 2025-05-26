#ifndef _PMERGEME_HPP_
# define _PMERGEME_HPP_

# include <iostream>
# include <vector>
# include <deque>
# include <string>
# include <cstdlib> 
# include <limits.h>
# include <ctime>

class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;
        bool isGood;

        bool containsSpaces( const std::string& s );
        std::vector<std::string> split(const std::string& str, char delimiter);
        int convertToInt(const std::string& str);
        int verifDouble( const std::vector<int>& vec );

        // Ford-Johnson algorithm functions for vector
        void fordJohnsonSortVector();
        std::vector<int> fordJohnsonRecursiveVector(std::vector<int>& arr);
        int binarySearchVector(const std::vector<int>& arr, int target, int left, int right);
        std::vector<int> generateJacobsthalSequence(int n);

        // Ford-Johnson algorithm functions for deque
        void fordJohnsonSortDeque();
        std::deque<int> fordJohnsonRecursiveDeque(std::deque<int>& arr);
        int binarySearchDeque(const std::deque<int>& arr, int target, int left, int right);

    public:

        //Basic functions
        PmergeMe();
        PmergeMe( int ac, char **av );
        ~PmergeMe();
        PmergeMe( const PmergeMe& copy );
        PmergeMe& operator=( const PmergeMe& other );

        void print() const ;
        bool getStatus();
        void sortAndMeasure();
};

#endif