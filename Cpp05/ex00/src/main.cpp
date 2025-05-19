#include "../inc/Bureaucrat.hpp"

int main()
{
    // Test 1: grade limite valide
    try {
        Bureaucrat a("Alice", 1);
        std::cout << a;
        a.incGrade(); // Doit throw (grade trop haut)
    } catch (const std::exception& e) {
        std::cerr << "Test 1 Exception : " << e.what() << std::endl;
    }

    // Test 2: création grade trop haut (0)
    try {
        Bureaucrat b("Bob", 0); // Doit throw
    } catch (const std::exception& e) {
        std::cerr << "Test 2 Exception : " << e.what() << std::endl;
    }

    // Test 3: création grade trop bas (151)
    try {
        Bureaucrat c("Charlie", 151); // Doit throw
    } catch (const std::exception& e) {
        std::cerr << "Test 3 Exception : " << e.what() << std::endl;
    }

    // Test 4: décrémentation normale
    try {
        Bureaucrat d("Diana", 42);
        std::cout << d;
        d.decGrade(); // OK
        std::cout << d;
    } catch (const std::exception& e) {
        std::cerr << "Test 4 Exception : " << e.what() << std::endl;
    }

    // Test 5: décrémentation trop loin
    try {
        Bureaucrat e("Eve", 150);
        std::cout << e;
        e.decGrade(); // Doit throw
    } catch (const std::exception& e) {
        std::cerr << "Test 5 Exception : " << e.what() << std::endl;
    }

    // Test 6: incrémentation normale
    try {
        Bureaucrat f("Frank", 2);
        std::cout << f;
        f.incGrade(); // OK → grade devient 1
        std::cout << f;
    } catch (const std::exception& e) {
        std::cerr << "Test 6 Exception : " << e.what() << std::endl;
    }

        // Test 7: constructeur de copie
    try {
        Bureaucrat original("Greg", 10);
        std::cout << "Original: " << original;
        Bureaucrat copy(original);  // Appelle le constructeur de copie
        std::cout << "Copie: Greg" << copy;
    } catch (const std::exception& e) {
        std::cerr << "Test 7 Exception : " << e.what() << std::endl;
    }

    // Test 8: opérateur d’assignation
    try {
        Bureaucrat h("Helen", 20);
        Bureaucrat i("Isabelle", 100);
        std::cout << "Avant assignation:\n";
        std::cout << "H: " << h;
        std::cout << "I: " << i;
        i = h;  // Appelle l’opérateur =
        std::cout << "Après assignation:\n";
        std::cout << "I: " << i;
    } catch (const std::exception& e) {
        std::cerr << "Test 8 Exception : " << e.what() << std::endl;
    }

    return 0;
}
