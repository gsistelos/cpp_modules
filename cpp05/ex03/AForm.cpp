#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm( void ) : _name("default"), _signed(false), _signGrade(1), _executeGrade(1)
{
}

AForm::AForm( std::string const & target, std::string const & name, int signGrade, int executeGrade )
: _name(name), _target(target), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (_signGrade < 1 || _executeGrade < 1)
		throw AForm::GradeTooHighException();
	if (_signGrade > 150 || _executeGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm( AForm const & other )
: _name(other._name), _target(other._target), _signed(other._signed), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
}

AForm::~AForm()
{
}

AForm& AForm::operator=( AForm const & other )
{
	_signed = other._signed;
	return *this;
}

std::string const & AForm::getName( void ) const
{
	return _name;
}

std::string const & AForm::getTarget( void ) const
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

void AForm::beSigned( Bureaucrat const & bureaucrat )
{
	if (bureaucrat.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	_signed = true;
}

void AForm::execute( Bureaucrat const & executor ) const
{
	if (_signed == false)
		throw AForm::FormNotSigned();
	if (executor.getGrade() > _executeGrade)
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

char const * AForm::FormNotSigned::what() const throw()
{
	return "Form not signed";
}

std::ostream& operator<<( std::ostream& os, AForm const & form )
{
	os << "name: " << form.getName() << "; signed: " << form.getSigned() << "; sign grade: "
		<< form.getSignGrade() << "; execute grade: " << form.getExecuteGrade() << ";" << std::endl;
	return os;
}
