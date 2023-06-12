#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form( void ) : _name("default"), _signed(false), _signGrade(1), _executeGrade(1)
{
}

Form::Form( std::string const & name, int signGrade, int executeGrade )
: _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (_signGrade < 1)
		throw Form::GradeTooHighException();
	if (_signGrade > 150)
		throw Form::GradeTooLowException();
	if (_executeGrade < 1)
		throw Form::GradeTooHighException();
	if (_executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form( Form const & other )
: _name(other.getName()), _signGrade(other.getSignGrade()), _executeGrade(other.getExecuteGrade())
{
	*this = other;
}

Form::~Form()
{
}

Form& Form::operator=( Form const & other )
{
	_signed = other.getSigned();
	return *this;
}

std::string const & Form::getName( void ) const
{
	return _name;
}

bool Form::getSigned( void ) const
{
	return _signed;
}

int Form::getSignGrade( void ) const
{
	return _signGrade;
}

int Form::getExecuteGrade( void ) const
{
	return _executeGrade;
}

void Form::beSigned( Bureaucrat const & bureaucrat )
{
	if (bureaucrat.getGrade() > getSignGrade())
		throw Form::GradeTooLowException();
	_signed = true;
}

char const * Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

char const * Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream& operator<<( std::ostream& os, Form const & form )
{
	os << "name: " << form.getName() << "; signed: " << form.getSigned() << "; sign grade: "
		<< form.getSignGrade() << "; execute grade: " << form.getExecuteGrade() << ";" << std::endl;
	return os;
}
