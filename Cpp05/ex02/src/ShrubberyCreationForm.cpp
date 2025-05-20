#include "../inc/ShrubberyCreationForm.hpp"

using std::string;
using std::cout;
using std::endl;

ShrubberyCreationForm::ShrubberyCreationForm() : _target("Default"){}

ShrubberyCreationForm::ShrubberyCreationForm( const string& target )
: AForm("ShrubberyCreationForm", 145, 137), _target(target){
    cout << "ShrubberyCreationForm " << _target << " created." << endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other )
{
    cout << "Operator = for isSigned" << endl;
    if (this != &other){
        this->_target = other._target;
    }
    return *this;
}

string ShrubberyCreationForm::getTarget() const
{
    return _target;
}

void ShrubberyCreationForm::execute( Bureaucrat const& executor ) const
{
    if (!this->getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > this->getGradeExec())
}