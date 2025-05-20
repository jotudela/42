#ifndef _ROBOTOMYREQUESTFORM_HPP_
# define _ROBOTOMYREQUESTFORM_HPP_

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
    public:

        //Basic functions
        RobotomyRequestForm();
        RobotomyRequestForm( const std::string& target );
        virtual ~RobotomyRequestForm();
        RobotomyRequestForm( const RobotomyRequestForm& copy );
        RobotomyRequestForm& operator=( const RobotomyRequestForm& other );

        virtual void execute( Bureaucrat const& executor ) const;
};

#endif