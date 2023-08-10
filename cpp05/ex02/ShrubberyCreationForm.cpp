#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("ShrubberyCreationForm", "default", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const & target ) : AForm("ShrubberyCreationForm", target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( AForm const & other )
: AForm(other.getName(), other.getTarget(), 145, 137)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( AForm const & other )
{
	AForm::operator=(other);
	return *this;
}

void ShrubberyCreationForm::beExecuted( void ) const
{
	std::ofstream file((getTarget() + "_target").c_str());

	file << "ASCII trees" << std::endl;
}
