#ifndef _INTERN_HPP_
# define _INTERN_HPP_

# include "AForm.hpp"

class Intern
{
    private:
        static AForm* makeShrubbery( const std::string& target );
        static AForm* makeRobotomy( const std::string& target );
        static AForm* makePresidential( const std::string& target) ;
    public:
        Intern();
        ~Intern();
        Intern( const Intern& copy );
        Intern& operator=( const Intern& other );

        AForm* makeForm( const std::string& formName, const std::string& target );
};

#endif