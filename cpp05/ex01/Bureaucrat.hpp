#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Bureaucrat
{
private:
	std::string const _name;
	int _grade;
public:
	Bureaucrat( void );
	Bureaucrat( std::string const & name, int grade );
	Bureaucrat( Bureaucrat const & other );

	~Bureaucrat();

	Bureaucrat& operator=( Bureaucrat const & other );

	std::string const & getName( void ) const;
	int getGrade( void ) const;
	void incrementGrade( int n );
	void decrementGrade( int n );
	void signForm( Form& form );

	class GradeTooHighException : public std::exception {
	public:
		char const * what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		char const * what() const throw();
	};
};

std::ostream& operator<<( std::ostream& os, Bureaucrat const & bureaucrat );

#endif /* BUREAUCRAT_HPP */
