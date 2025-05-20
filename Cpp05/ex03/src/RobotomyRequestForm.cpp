#include "../inc/RobotomyRequestForm.hpp"

using std::string;
using std::cout;
using std::endl;

RobotomyRequestForm::RobotomyRequestForm() : AForm(), _target("Default"){}

RobotomyRequestForm::RobotomyRequestForm( const string& target )
: AForm("RobotomyRequestForm", 72, 45), _target(target){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& copy )
: AForm(copy), _target(copy._target){
    cout << "Copy constructor called" << endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& other )
{
    cout << "Operator = called" << endl;
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

void RobotomyRequestForm::execute( Bureaucrat const& executor ) const
{
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeExec())
        throw AForm::GradeTooLowException();

    cout << "BZZZZZZZZZZZZZ... (drilling noises)" << endl;

    std::srand(std::time(NULL)); // initialise rand
    if (std::rand() % 2)
        cout << _target << " has been robotomized successfully!" << endl;
    else
        cout << "Robotomy of " << _target << " failed." << endl;
}