#ifndef _PRESIDENTIALPARDONFORM_HPP_
# define _PRESIDENTIALPARDONFORM_HPP_

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
    public:

        //Basic functions
        PresidentialPardonForm();
        PresidentialPardonForm( const std::string& target );
        virtual ~PresidentialPardonForm();
        PresidentialPardonForm( const PresidentialPardonForm& copy );
        PresidentialPardonForm& operator=( const PresidentialPardonForm& other );

        virtual void execute( Bureaucrat const& executor ) const;
};

#endif