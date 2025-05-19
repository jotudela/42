#ifndef _FORM_HPP_
# define _FORM_HPP_

# include "Bureaucrat.hpp"

class Form : public Bureaucrat
{
    private:
        const std::string _name;
        bool _isSigned;
        const size_t _gradeSign;
        const size_t _gradeExec;
    public:

        //Classic functions
        Form();
        Form( const std::string name, const size_t gradeSign, const size_t gradeExec );
        ~Form();

        Form( Form const& copy ) :
            _name(copy._name),
            _isSigned(copy._isSigned),
            _gradeSign(copy._gradeSign),
            _gradeExec(copy._gradeExec){
                std::cout << "Copy constructor called" << std::endl;
            }

        Form& operator=( const Form& other );

        //Getters functions
        const std::string getFormName() const;
        bool getIsSigned() const;
        const size_t getGradeSign() const;
        const size_t getGradeExec() const;

        //Other functions
        void beSigned( Bureaucrat& bureaucrat );

        //Exceptions functions
        class GradeTooHightException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Grade too hight to sign or execute form!";
                }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Grade too low to sign or execute form!";
                }
        };
};

std::ostream &operator<<( std::ostream &out, Form &_form );

#endif