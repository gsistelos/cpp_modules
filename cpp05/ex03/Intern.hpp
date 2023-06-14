#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	Intern( void );
	Intern( Intern const & other );

	~Intern();

	Intern& operator=( Intern const & other );

	AForm* makeForm( std::string const & name, std::string const & target );

	class InvalidFormException : public std::exception {
	public:
		char const * what() const throw();
	};
};

#endif /* INTERN_HPP */
