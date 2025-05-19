#include "../inc/Bureaucrat.hpp"

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

const string Bureaucrat::getName()
{
    return _name;
}

size_t Bureaucrat::getGrade()
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

void Bureaucrat::signForm(Form& form)
{
    try {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << this->_name << " couldn’t sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

ostream &operator<<( ostream &out, Bureaucrat &_bureaucrat )
{
    out << _bureaucrat.getName() << ", bureaucrat grade "<< _bureaucrat.getGrade() << "." << endl;
    return out;
}