#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"
#include <iostream>

int main()
{
    // Tests Bureaucrat
    try {
        Bureaucrat a("Alice", 1);
        std::cout << a;
        a.incGrade(); // Doit throw (grade trop haut)
    } catch (const std::exception& e) {
        std::cerr << "Test 1 Exception : " << e.what() << std::endl;
    }

    try {
        Bureaucrat b("Bob", 0); // Doit throw
    } catch (const std::exception& e) {
        std::cerr << "Test 2 Exception : " << e.what() << std::endl;
    }

    try {
        Bureaucrat c("Charlie", 151); // Doit throw
    } catch (const std::exception& e) {
        std::cerr << "Test 3 Exception : " << e.what() << std::endl;
    }

    try {
        Bureaucrat d("Diana", 42);
        std::cout << d;
        d.decGrade(); // OK
        std::cout << d;
    } catch (const std::exception& e) {
        std::cerr << "Test 4 Exception : " << e.what() << std::endl;
    }

    try {
        Bureaucrat e("Eve", 150);
        std::cout << e;
        e.decGrade(); // Doit throw
    } catch (const std::exception& e) {
        std::cerr << "Test 5 Exception : " << e.what() << std::endl;
    }

    try {
        Bureaucrat f("Frank", 2);
        std::cout << f;
        f.incGrade(); // OK → grade devient 1
        std::cout << f;
    } catch (const std::exception& e) {
        std::cerr << "Test 6 Exception : " << e.what() << std::endl;
    }

    try {
        Bureaucrat original("Greg", 10);
        std::cout << "Original: " << original;
        Bureaucrat copy(original);
        std::cout << "Copie: " << copy;
    } catch (const std::exception& e) {
        std::cerr << "Test 7 Exception : " << e.what() << std::endl;
    }

    try {
        Bureaucrat h("Helen", 20);
        Bureaucrat i("Isabelle", 100);
        std::cout << "Avant assignation:\n";
        std::cout << "H: " << h;
        std::cout << "I: " << i;
        i = h;
        std::cout << "Après assignation:\n";
        std::cout << "I: " << i;
    } catch (const std::exception& e) {
        std::cerr << "Test 8 Exception : " << e.what() << std::endl;
    }

    // -------------------------
    // Tests Formulaires
    // -------------------------

    try {
        Bureaucrat j("James", 50);
        Form formA("TaxForm", 100, 100); // Signature facile
        j.signForm(formA);
    } catch (const std::exception& e) {
        std::cerr << "Test 9 Exception : " << e.what() << std::endl;
    }

    try {
        Bureaucrat k("Kate", 120);
        Form formB("TopSecret", 50, 30); // Signature impossible
        k.signForm(formB);
    } catch (const std::exception& e) {
        std::cerr << "Test 10 Exception : " << e.what() << std::endl;
    }

    try {
        Bureaucrat l("Leo", 10);
        Form formC("VIPAccess", 10, 5); // Exactement suffisant
        l.signForm(formC);
    } catch (const std::exception& e) {
        std::cerr << "Test 11 Exception : " << e.what() << std::endl;
    }

    return 0;
}
