#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("PresidentialPardonForm", "default", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm( std::string const & target ) : AForm("PresidentialPardonForm", target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm( AForm const & other )
: AForm(other.getName(), other.getTarget(), 25, 5)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=( AForm const & other )
{
	AForm::operator=(other);
	return *this;
}

void PresidentialPardonForm::beExecuted( void ) const
{
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
