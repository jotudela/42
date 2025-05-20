#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

using std::cout;
using std::string;
using std::endl;
using std::ostream;

Bureaucrat::Bureaucrat() : _name("Default"), _grade(100){}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat( const string name, size_t grade ) : _name(name)
{
    if (grade < 1)
        throw GradeTooHightException();
    else if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat( Bureaucrat const& copy )
{
    cout << "Copy constructor called" << endl;
    *this = copy;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other )
{
    cout << "Copy assignment operator called" << endl;
    if (this != &other){
        this->_grade = other._grade;
    }
    return *this;
}

const string Bureaucrat::getName() const
{
    return _name;
}

size_t Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::incGrade()
{
    if ((this->_grade - 1) <= 0)
        throw GradeTooHightException();
    this->_grade -= 1;
}

void Bureaucrat::decGrade()
{
    if ((this->_grade + 1) >= 151)
        throw GradeTooLowException();
    this->_grade += 1;
}

void Bureaucrat::signForm( AForm& form )
{
    try {
        form.beSigned(*this);
        cout << this->_name << " signed " << form.getAFormName() << endl;
    } catch (const std::exception& e) {
        cout << this->_name << " couldn't sign " << form.getAFormName()
                  << " because " << e.what() << endl;
    }
}

void Bureaucrat::executeForm( AForm const& form ) const
{
    try {
        form.execute(*this);
        cout << this->_name << " executed " << form.getAFormName() << endl;
    } catch (const std::exception& e) {
        cout << this->_name << " couldn't execute " << form.getAFormName()
                  << " because " << e.what() << endl;
    }
}

ostream &operator<<( ostream &out, Bureaucrat &_bureaucrat )
{
    out << _bureaucrat.getName() << ", bureaucrat grade "<< _bureaucrat.getGrade() << "." << endl;
    return out;
}