#include "iter.hpp"

// Fonction de lecture (const)
template <typename T>
void printElement(const T& x) {
    std::cout << x << std::endl;
}

// Fonction de modification (non-const)
template <typename T>
void increment(T& x) {
    x += 1;
}

int main() {
    // Tableau non-const
    int array1[] = {1, 2, 3, 4, 5};
    int len1 = sizeof(array1) / sizeof(array1[0]);

    std::cout << "Avant incrementation :" << std::endl;
    iter(array1, len1, printElement);
    std::cout << "Apres incrementation :" << std::endl;
    iter(array1, len1, static_cast<void(*)(int&)>(increment<int>));
    iter(array1, len1, static_cast<void(*)(const int&)>(printElement<int>));

    return 0;
}