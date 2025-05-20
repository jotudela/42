#include "../inc/Form.hpp"

using std::cout;
using std::string;
using std::endl;
using std::ostream;

Form::Form() : _name("Default"), _isSigned(false), _gradeSign(1), _gradeExec(100){}

Form::Form( const std::string name, const size_t gradeSign, const size_t gradeExec ) : 
_name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec){}

Form::~Form(){}

Form& Form::operator=( const Form& other )
{
    cout << "Operator = for isSigned" << endl;
    if (this != &other){
        this->_isSigned = other._isSigned;
    }
    return *this;
}

const string Form::getFormName() const
{
    return _name;
}

bool Form::getIsSigned() const
{
    return _isSigned;
}

size_t Form::getGradeSign() const
{
    return _gradeSign;
}

size_t Form::getGradeExec() const
{
    return _gradeExec;
}

void Form::beSigned( Bureaucrat& bureaucrat )
{
    if (bureaucrat.getGrade() > this->_gradeSign)
        throw Form::GradeTooLowException();
    this->_isSigned = true;
}

ostream &operator<<( ostream &out, Form &_form )
{
    out << "Form name : " << _form.getFormName()
        << ", form signed status : " << _form.getIsSigned()
        << ", form grade need to sign : " << _form.getGradeSign()
        << ", form grade need to execute : " << _form.getGradeExec()
        << "." << endl;
    return out;
}