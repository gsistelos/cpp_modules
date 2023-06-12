#include "Bureaucrat.hpp"

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

Bureaucrat::Bureaucrat( Bureaucrat const & other ) : _name(other.getName())
{
	*this = other;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=( Bureaucrat const & other )
{
	_grade = other.getGrade();
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

void Bureaucrat::incrementGrade( int n )
{
	if (_grade - n < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade -= n;
}

void Bureaucrat::decrementGrade( int n )
{
	if (_grade + n > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade += n;
}

void Bureaucrat::signForm(Form& form)
{
	try {
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	} catch (std::exception & e) {
		std::cerr << getName() << " couldn't sing " <<
			form.getName() << " because " << e.what() << std::endl;
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

std::ostream& operator<<( std::ostream& os, Bureaucrat const & bureaucrat ) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
  return os;
}
