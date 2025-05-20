#include "../inc/AForm.hpp"

using std::cout;
using std::string;
using std::endl;
using std::ostream;

AForm::AForm() : _name("Default"), _isSigned(false), _gradeSign(1), _gradeExec(100){}

AForm::AForm( const std::string name, const size_t gradeSign, const size_t gradeExec ) : 
_name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec){}

AForm::~AForm(){}

AForm& AForm::operator=( const AForm& other )
{
    cout << "Operator = for isSigned" << endl;
    if (this != &other){
        this->_isSigned = other._isSigned;
    }
    return *this;
}

const string AForm::getAFormName() const
{
    return _name;
}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

size_t AForm::getGradeSign() const
{
    return _gradeSign;
}

size_t AForm::getGradeExec() const
{
    return _gradeExec;
}

void AForm::beSigned( Bureaucrat& bureaucrat )
{
    if (bureaucrat.getGrade() > this->_gradeSign)
        throw AForm::GradeTooLowException();
    this->_isSigned = true;
}

ostream &operator<<( ostream &out, AForm &_Aform )
{
    out << "Form name : " << _Aform.getAFormName()
        << ", form signed status : " << _Aform.getIsSigned()
        << ", form grade need to sign : " << _Aform.getGradeSign()
        << ", form grade need to execute : " << _Aform.getGradeExec()
        << "." << endl;
    return out;
}