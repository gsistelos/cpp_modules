#include "Intern.hpp"

Intern::Intern( void )
{
}

Intern::Intern( Intern const & other )
{
	*this = other;
}

Intern::~Intern()
{
}

Intern& Intern::operator=( Intern const & other )
{
	(void)other;
	return *this;
}

AForm* Intern::makeForm( std::string const & name, std::string const & target )
{
	AForm* form = NULL;

	try {
		if (name == "ShrubberyCreationForm")
			form = new ShrubberyCreationForm(target);
		else if (name == "RobotomyRequestForm")
			form = new RobotomyRequestForm(target);
		else if (name == "PresidentialPardonForm")
			form = new PresidentialPardonForm(target);
		else
			throw Intern::InvalidFormException();
		std::cout << "Intern creates " << name << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Intern couldn't create " <<
			name << " because " << e.what() << std::endl;
	}
	return form;
}

char const * Intern::InvalidFormException::what() const throw()
{
	return "Invalid form";
}
