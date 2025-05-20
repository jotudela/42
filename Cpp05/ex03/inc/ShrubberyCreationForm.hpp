#ifndef _SHRUBBERYCREATIONFORM_HPP_
# define _SHRUBBERYCREATIONFORM_HPP_

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    public:
    
        //Basic functions
        ShrubberyCreationForm();
        ShrubberyCreationForm( const std::string& target );
        virtual ~ShrubberyCreationForm();
        ShrubberyCreationForm( ShrubberyCreationForm const& copy );
        ShrubberyCreationForm& operator=( const ShrubberyCreationForm& other );

        //Getters function
        std::string getTarget() const;

        //Other functions
        virtual void execute( Bureaucrat const& executor ) const;
};

#endif