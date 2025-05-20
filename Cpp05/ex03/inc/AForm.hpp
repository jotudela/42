#ifndef _AAForm_HPP_
# define _AAForm_HPP_

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        const size_t _gradeSign;
        const size_t _gradeExec;
    public:

        //Classic functions
        AForm();
        AForm( const std::string name, const size_t gradeSign, const size_t gradeExec );
        virtual ~AForm();

        AForm( AForm const& copy ) :
            _name(copy._name),
            _isSigned(copy._isSigned),
            _gradeSign(copy._gradeSign),
            _gradeExec(copy._gradeExec){
                std::cout << "Copy constructor called" << std::endl;
            }

        AForm& operator=( const AForm& other );

        //Getters functions
        const std::string getAFormName() const;
        bool getIsSigned() const;
        size_t getGradeSign() const;
        size_t getGradeExec() const;

        //Other functions
        void beSigned( Bureaucrat& bureaucrat );

        //Abstract function
        virtual void execute( Bureaucrat const& executor ) const = 0;

        //Exceptions functions
        class GradeTooHightException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Grade too high to sign this AForm!";
                }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Grade too low to sign this AForm!";
                }
        };

        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Form is not signed, cannot be executed!";
                }
        };
};

std::ostream &operator<<( std::ostream &out, AForm &_AForm );

#endif