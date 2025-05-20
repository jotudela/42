#include "../inc/ShrubberyCreationForm.hpp"

using std::string;
using std::cout;
using std::endl;
using std::ofstream;

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), _target("Default"){}

ShrubberyCreationForm::ShrubberyCreationForm( const string& target )
: AForm("ShrubberyCreationForm", 145, 137), _target(target){
    cout << "ShrubberyCreationForm " << _target << " created." << endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const& copy )
: AForm(copy), _target(copy._target){
    cout << "Copy constructor called" << endl; 
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other )
{
    cout << "Operator = called" << endl;
    if (this != &other)
    {
        AForm::operator=(other);
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
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeExec())
        throw AForm::GradeTooLowException();
    ofstream outfile((this->getTarget() + "_shrubbery").c_str());
    if (!outfile)
        throw std::ios_base::failure("Failed to open output file.");
    outfile << "       _-_\n"
               "    /~~   ~~\\\n"
               " /~~         ~~\\\n"
               "{               }\n"
               " \\  _-     -_  /\n"
               "   ~  \\\\ //  ~\n"
               "_- -   | | _- _\n"
               "  _ -  | |   -_\n"
               "      // \\\\\n";
    outfile.close();
}