#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int main()
{
    std::cout << "===== TEST ShrubberyCreationForm =====" << std::endl;
    try {
        Bureaucrat b1("Bob", 1);
        ShrubberyCreationForm f1("home");
        b1.signForm(f1);
        b1.executeForm(f1);
    } catch (const std::exception& e) {
        std::cerr << "Shrubbery Test Error: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST RobotomyRequestForm =====" << std::endl;
    try {
        Bureaucrat b2("Alice", 40); // Suffisant pour signer (72) et exécuter (45)
        RobotomyRequestForm f2("marvin");
        b2.signForm(f2);
        b2.executeForm(f2);
        b2.executeForm(f2); // Appel plusieurs fois pour voir le 50%
    } catch (const std::exception& e) {
        std::cerr << "Robotomy Test Error: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST PresidentialPardonForm =====" << std::endl;
    try {
        Bureaucrat b3("President", 1); // Très haut grade
        PresidentialPardonForm f3("Ford Prefect");
        b3.signForm(f3);
        b3.executeForm(f3);
    } catch (const std::exception& e) {
        std::cerr << "Presidential Test Error: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST ÉCHEC de Signature/Exécution =====" << std::endl;
    try {
        Bureaucrat low("LowRank", 150);
        ShrubberyCreationForm badForm("backyard");
        low.signForm(badForm);       // Trop faible pour signer
        low.executeForm(badForm);    // Et exécuter
    } catch (const std::exception& e) {
        std::cerr << "Failure Test Error: " << e.what() << std::endl;
    }

    return 0;
}
