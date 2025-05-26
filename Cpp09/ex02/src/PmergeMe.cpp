#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe( int ac, char **av ) : isGood(true)
{
    if (ac == 2 && containsSpaces(av[1]))
    {
        std::vector<std::string> tokens = split(av[1], ' ');
        for (size_t i = 0; i < tokens.size(); ++i)
        {
            int val = convertToInt(tokens[i]);
            if (val == -1){
                std::cerr << "Error: value is under 0" << std::endl;
                isGood = false;
                return ;
            }
            _vector.push_back(val);
            _deque.push_back(val);
        }
    }
    else
    {
        for (int i = 1; i < ac; ++i)
        {
            int val = convertToInt(av[i]);
            if (val == -1){
                std::cerr << "Error: value is under 0" << std::endl;
                isGood = false;
                return ;
            }
            _vector.push_back(val);
            _deque.push_back(val);
        }
    }
    if (verifDouble(_vector) == -1)
    {
        std::cerr << "Error: there is number in double" << std::endl;
        isGood = false;
        return ;
    }
}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe( const PmergeMe& copy )
: _vector(copy._vector), _deque(copy._deque), isGood(copy.isGood){}

PmergeMe& PmergeMe::operator=( const PmergeMe& other )
{
    if (this != &other)
    {
        _vector = other._vector;
        _deque = other._deque;
        isGood = other.isGood;
    }
    return *this;
}

std::vector<std::string> PmergeMe::split(const std::string& str, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    for (size_t i = 0; i < str.size(); ++i)
    {
        if (str[i] == delimiter)
        {
            if (!token.empty())
            {
                tokens.push_back(token);
                token.clear();
            }
        }
        else
        {
            token += str[i];
        }
    }
    if (!token.empty())
        tokens.push_back(token);
    return tokens;
}

bool PmergeMe::containsSpaces(const std::string& s)
{
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == ' ')
            return true;
    }
    return false;
}

int PmergeMe::convertToInt(const std::string& str)
{
    char* end;
    long val = std::strtol(str.c_str(), &end, 10);

    if (*end != '\0' || str.empty())
        return -1;

    if (val < 0 || val > INT_MAX)
        return -1;

    return static_cast<int>(val);
}

int PmergeMe::verifDouble( const std::vector<int>& vec )
{
    for (size_t i = 0; i < vec.size(); ++i) {
        int valeur = vec[i];

        for (size_t j = 0; j < vec.size(); ++j) {
            if (i != j && vec[j] == valeur) {
                return -1;
            }
        }
    }
    return 0;
}

void PmergeMe::print() const
{
    for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

bool PmergeMe::getStatus()
{
    return isGood;
}

// Ford-Johnson algorithm implementation for vector
std::vector<int> PmergeMe::generateJacobsthalSequence(int n)
{
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    
    int i = 2;
    while (jacobsthal[i-1] < n)
    {
        int next = jacobsthal[i-1] + 2 * jacobsthal[i-2];
        jacobsthal.push_back(next);
        i++;
    }
    return jacobsthal;
}

int PmergeMe::binarySearchVector(const std::vector<int>& arr, int target, int left, int right)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

std::vector<int> PmergeMe::fordJohnsonRecursiveVector(std::vector<int>& arr)
{
    int n = arr.size();
    
    if (n <= 1)
        return arr;
    
    // Step 1: Group into pairs and sort each pair
    std::vector<int> larger, smaller;
    int unpaired = -1;
    
    for (int i = 0; i + 1 < n; i += 2)
    {
        if (arr[i] > arr[i + 1])
        {
            larger.push_back(arr[i]);
            smaller.push_back(arr[i + 1]);
        }
        else
        {
            larger.push_back(arr[i + 1]);
            smaller.push_back(arr[i]);
        }
    }
    
    if (n % 2 == 1)
        unpaired = arr[n - 1];
    
    // Step 2: Recursively sort the larger elements
    larger = fordJohnsonRecursiveVector(larger);
    
    // Step 3: Create main chain with first smaller element
    std::vector<int> mainChain;
    if (!smaller.empty())
        mainChain.push_back(smaller[0]);
    
    for (size_t i = 0; i < larger.size(); ++i)
        mainChain.push_back(larger[i]);
    
    // Step 4: Insert remaining smaller elements using Jacobsthal sequence
    std::vector<int> jacobsthal = generateJacobsthalSequence(smaller.size());
    std::vector<bool> inserted(smaller.size(), false);
    
    if (!smaller.empty())
        inserted[0] = true;
    
    for (size_t i = 2; i < jacobsthal.size() && jacobsthal[i] <= static_cast<int>(smaller.size()); ++i)
    {
        int limit = jacobsthal[i];
        for (int j = limit - 1; j >= jacobsthal[i-1] && j < static_cast<int>(smaller.size()); --j)
        {
            if (!inserted[j])
            {
                int pos = binarySearchVector(mainChain, smaller[j], 0, mainChain.size() - 1);
                mainChain.insert(mainChain.begin() + pos, smaller[j]);
                inserted[j] = true;
            }
        }
    }
    
    // Insert any remaining smaller elements
    for (size_t i = 0; i < smaller.size(); ++i)
    {
        if (!inserted[i])
        {
            int pos = binarySearchVector(mainChain, smaller[i], 0, mainChain.size() - 1);
            mainChain.insert(mainChain.begin() + pos, smaller[i]);
        }
    }
    
    // Insert unpaired element if exists
    if (unpaired != -1)
    {
        int pos = binarySearchVector(mainChain, unpaired, 0, mainChain.size() - 1);
        mainChain.insert(mainChain.begin() + pos, unpaired);
    }
    
    return mainChain;
}

void PmergeMe::fordJohnsonSortVector()
{
    _vector = fordJohnsonRecursiveVector(_vector);
}

// Ford-Johnson algorithm implementation for deque
int PmergeMe::binarySearchDeque(const std::deque<int>& arr, int target, int left, int right)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

std::deque<int> PmergeMe::fordJohnsonRecursiveDeque(std::deque<int>& arr)
{
    int n = arr.size();
    
    if (n <= 1)
        return arr;
    
    // Step 1: Group into pairs and sort each pair
    std::deque<int> larger, smaller;
    int unpaired = -1;
    
    for (int i = 0; i + 1 < n; i += 2)
    {
        if (arr[i] > arr[i + 1])
        {
            larger.push_back(arr[i]);
            smaller.push_back(arr[i + 1]);
        }
        else
        {
            larger.push_back(arr[i + 1]);
            smaller.push_back(arr[i]);
        }
    }
    
    if (n % 2 == 1)
        unpaired = arr[n - 1];
    
    // Step 2: Recursively sort the larger elements
    larger = fordJohnsonRecursiveDeque(larger);
    
    // Step 3: Create main chain with first smaller element
    std::deque<int> mainChain;
    if (!smaller.empty())
        mainChain.push_back(smaller[0]);
    
    for (size_t i = 0; i < larger.size(); ++i)
        mainChain.push_back(larger[i]);
    
    // Step 4: Insert remaining smaller elements using Jacobsthal sequence
    std::vector<int> jacobsthal = generateJacobsthalSequence(smaller.size());
    std::deque<bool> inserted(smaller.size(), false);
    
    if (!smaller.empty())
        inserted[0] = true;
    
    for (size_t i = 2; i < jacobsthal.size() && jacobsthal[i] <= static_cast<int>(smaller.size()); ++i)
    {
        int limit = jacobsthal[i];
        for (int j = limit - 1; j >= jacobsthal[i-1] && j < static_cast<int>(smaller.size()); --j)
        {
            if (!inserted[j])
            {
                int pos = binarySearchDeque(mainChain, smaller[j], 0, mainChain.size() - 1);
                mainChain.insert(mainChain.begin() + pos, smaller[j]);
                inserted[j] = true;
            }
        }
    }
    
    // Insert any remaining smaller elements
    for (size_t i = 0; i < smaller.size(); ++i)
    {
        if (!inserted[i])
        {
            int pos = binarySearchDeque(mainChain, smaller[i], 0, mainChain.size() - 1);
            mainChain.insert(mainChain.begin() + pos, smaller[i]);
        }
    }
    
    // Insert unpaired element if exists
    if (unpaired != -1)
    {
        int pos = binarySearchDeque(mainChain, unpaired, 0, mainChain.size() - 1);
        mainChain.insert(mainChain.begin() + pos, unpaired);
    }
    
    return mainChain;
}

void PmergeMe::fordJohnsonSortDeque()
{
    _deque = fordJohnsonRecursiveDeque(_deque);
}

void PmergeMe::sortAndMeasure()
{
    std::cout << "Before: ";
    print();
    
    // Measure time for vector sorting
    clock_t start = clock();
    fordJohnsonSortVector();
    clock_t end = clock();
    double vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    
    // Measure time for deque sorting
    start = clock();
    fordJohnsonSortDeque();
    end = clock();
    double dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    
    std::cout << "After:  ";
    print();
    
    std::cout << "Time to process a range of " << _vector.size() 
              << " elements with std::vector : " << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size() 
              << " elements with std::deque  : " << dequeTime << " us" << std::endl;
}