#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("RobotomyRequestForm", "default", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm( std::string const & target ) : AForm("RobotomyRequestForm", target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm( AForm const & other )
: AForm(other.getName(), other.getTarget(), 72, 45)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=( AForm const & other )
{
	AForm::operator=(other);
	return *this;
}

void RobotomyRequestForm::beExecuted( void ) const
{
	std::cout << "* drilling noises *" << std::endl;
	std::cout << getTarget() << " has been robotomized successfully 50%% of the time" << std::endl;
}
