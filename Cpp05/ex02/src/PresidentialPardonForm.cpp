#include "../inc/PresidentialPardonForm.hpp"

using std::string;
using std::cout;
using std::endl;

PresidentialPardonForm::PresidentialPardonForm() : AForm(), _target("Default"){}

PresidentialPardonForm::PresidentialPardonForm( const string& target )
: AForm("PresidentialPardonForm", 25, 5), _target(target){}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& copy )
: AForm(copy), _target(copy._target){
    cout << "Copy constructor called" << endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& other )
{
    cout << "Operator = called" << endl;
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

void PresidentialPardonForm::execute( Bureaucrat const& executor ) const
{
    if (!getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeExec())
        throw AForm::GradeTooLowException();

    cout << _target << " has been pardoned by Zaphod Beeblebrox." << endl;
}