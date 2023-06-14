#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm( void ) : _name("default"), _target("default"), _signed(false), _signGrade(1), _executeGrade(1)
{
}

AForm::AForm( std::string const & name, std::string const & target, int signGrade, int executeGrade )
: _name(name), _target(target), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (_signGrade < 1)
		throw AForm::GradeTooHighException();
	if (_signGrade > 150)
		throw AForm::GradeTooLowException();
	if (_executeGrade < 1)
		throw AForm::GradeTooHighException();
	if (_executeGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm( AForm const & other )
: _name(other.getName()), _signGrade(other.getSignGrade()), _executeGrade(other.getExecuteGrade())
{
	*this = other;
}

AForm::~AForm()
{
}

AForm& AForm::operator=( AForm const & other )
{
	_signed = other.getSigned();
	return *this;
}

std::string const & AForm::getName( void ) const
{
	return _name;
}

std::string AForm::getTarget( void ) const
{
	return _target;
}

bool AForm::getSigned( void ) const
{
	return _signed;
}

int AForm::getSignGrade( void ) const
{
	return _signGrade;
}

int AForm::getExecuteGrade( void ) const
{
	return _executeGrade;
}

void AForm::setSigned( bool state )
{
	_signed = state;
}

void AForm::beSigned( Bureaucrat const & bureaucrat )
{
	if (bureaucrat.getGrade() > getSignGrade())
		throw AForm::GradeTooLowException();
	_signed = true;
}

void AForm::execute( Bureaucrat const & bureaucrat ) const
{
	if (getSigned() == false)
		throw AForm::FormNotSignedException();
	if (bureaucrat.getGrade() > getExecuteGrade())
		throw AForm::GradeTooLowException();
	beExecuted();
}

char const * AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

char const * AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

char const * AForm::FormNotSignedException::what() const throw()
{
	return "Form not signed";
}

std::ostream& operator<<( std::ostream& os, AForm const & form )
{
	os << "name: " << form.getName() << "; signed: " << form.getSigned() << "; sign grade: "
		<< form.getSignGrade() << "; execute grade: " << form.getExecuteGrade() << ";" << std::endl;
	return os;
}
