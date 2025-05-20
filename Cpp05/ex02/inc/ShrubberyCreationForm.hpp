#ifndef _SHRUBBERYCREATIONFORM_HPP_
# define _SHRUBBERYCREATIONFORM_HPP_

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    public:
    
        //Basic functions
        ShrubberyCreationForm();
        ShrubberyCreationForm( const std::string& target );
        virtual ~ShrubberyCreationForm();

        ShrubberyCreationForm( ShrubberyCreationForm const& copy ) :
            _target(copy._target){
                std::cout << "Copy constructor called" << std::endl; 
            }

        ShrubberyCreationForm& operator=( const ShrubberyCreationForm& other );

        //Getters function
        std::string getTarget() const;

        //Other functions
        virtual void execute( Bureaucrat const& executor ) const;

        //Exception
        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Form is not signed, cannot be executed!";
                }
        };
};

#endif