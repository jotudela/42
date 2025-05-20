#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"

int main()
{
    Intern someRandomIntern;

    // Test 1 : création ShrubberyCreationForm
    AForm* shrubForm = someRandomIntern.makeForm("shrubbery creation", "Home");
    if (shrubForm) {
        std::cout << *shrubForm << std::endl;
        delete shrubForm;
    }

    // Test 2 : création RobotomyRequestForm
    AForm* robotForm = someRandomIntern.makeForm("robotomy request", "Bender");
    if (robotForm) {
        std::cout << *robotForm << std::endl;
        delete robotForm;
    }

    // Test 3 : création PresidentialPardonForm
    AForm* pardonForm = someRandomIntern.makeForm("presidential pardon", "Marvin");
    if (pardonForm) {
        std::cout << *pardonForm << std::endl;
        delete pardonForm;
    }

    // Test 4 : tentative de création d’un formulaire inconnu
    AForm* unknownForm = someRandomIntern.makeForm("unknown form", "Target");
    if (unknownForm) {
        std::cout << *unknownForm << std::endl;
        delete unknownForm;
    }

    return 0;
}
