#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat( void ) : _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat( std::string const & name, int grade ) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat( Bureaucrat const & other ) : _name(other._name), _grade(other._grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=( Bureaucrat const & other )
{
	_grade = other._grade;
	return *this;
}

std::string const & Bureaucrat::getName( void ) const
{
	return _name;
}

int Bureaucrat::getGrade( void ) const
{
	return _grade;
}

void Bureaucrat::incrementGrade( void )
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade( void )
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm( AForm& form)
{
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm( AForm const & form )
{
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

char const * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

char const * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream& operator<<( std::ostream& os, Bureaucrat const & bureaucrat )
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}
