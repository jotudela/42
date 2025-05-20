#include "../inc/Intern.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern( const Intern& copy )
{
    (void)copy;
}

Intern& Intern::operator=( Intern const& other )
{
    (void)other;
    return *this;
}

AForm* Intern::makeShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    struct FormPair {
        std::string name;
        AForm* (*create)(const std::string&);
    };

    FormPair forms[] = {
        {"shrubbery creation", &Intern::makeShrubbery},
        {"robotomy request", &Intern::makeRobotomy},
        {"presidential pardon", &Intern::makePresidential}
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == forms[i].name) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].create(target);
        }
    }
    std::cout << "Intern cannot create form because form name \"" << formName << "\" is unknown." << std::endl;
    return NULL;
}