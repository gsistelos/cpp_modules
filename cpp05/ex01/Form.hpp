#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
private:
	std::string const _name;
	bool _signed;
	int const _signGrade;
	int const _executeGrade;
public:
	Form( void );
	Form( std::string const & name, int signGrade, int executeGrade );
	Form( Form const & other );

	~Form();

	Form& operator=( Form const & other );

	std::string const & getName( void ) const;
	bool getSigned( void ) const;
	int getSignGrade( void ) const;
	int getExecuteGrade( void ) const;
	void beSigned( Bureaucrat const & bureaucrat );

	class GradeTooHighException : public std::exception {
	public:
		char const * what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		char const * what() const throw();
	};
};

std::ostream& operator<<( std::ostream& os, Form const & form );

#endif /* FORM_HPP */
