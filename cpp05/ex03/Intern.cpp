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
	std::string str[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	try {
		int i;
		for (i = 0; i < 3; i++) {
			if (str[i] == name)
				break;
		}
		switch (i) {
			case 0:
				form = new ShrubberyCreationForm(target);
				break ;
			case 1:
				form = new RobotomyRequestForm(target);
				break ;
			case 2:
				form = new PresidentialPardonForm(target);
				break ;
			default:
				throw Intern::InvalidFormException();
				break ;
		}
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
