#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
private:
	std::string const _name;
	std::string _target;
	bool _signed;
	int const _signGrade;
	int const _executeGrade;
public:
	AForm( void );
	AForm( std::string const & name, std::string const & target, int signGrade, int executeGrade );
	AForm( AForm const & other );

	virtual ~AForm();

	AForm& operator=( AForm const & other );

	std::string const & getName( void ) const;
	std::string getTarget( void ) const;
	bool getSigned( void ) const;
	int getSignGrade( void ) const;
	int getExecuteGrade( void ) const;
	void setSigned( bool state );
	void beSigned( Bureaucrat const & bureaucrat );
	void execute( Bureaucrat const & bureaucrat ) const;
	virtual void beExecuted( void ) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		char const * what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		char const * what() const throw();
	};

	class FormNotSignedException : public std::exception {
	public:
		char const * what() const throw();
	};
};

std::ostream& operator<<( std::ostream& os, AForm const & form );

#endif /* AFORM_HPP */
