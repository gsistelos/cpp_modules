#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{
	ShrubberyCreationForm shrubbery;
	RobotomyRequestForm robotomy;
	PresidentialPardonForm presidential;

	Bureaucrat gguedes("gguedes", 87);
	Bureaucrat grsaiago("grsaiago", 10);
	Bureaucrat admin("admin", 1);

	grsaiago.executeForm(shrubbery);
	grsaiago.executeForm(robotomy);
	grsaiago.executeForm(presidential);

	gguedes.signForm(shrubbery);
	gguedes.signForm(robotomy);
	gguedes.signForm(presidential);

	grsaiago.signForm(shrubbery);
	grsaiago.signForm(robotomy);
	grsaiago.signForm(presidential);

	gguedes.executeForm(shrubbery);
	gguedes.executeForm(robotomy);
	gguedes.executeForm(presidential);

	grsaiago.executeForm(shrubbery);
	grsaiago.executeForm(robotomy);
	grsaiago.executeForm(presidential);

	admin.executeForm(presidential);

	return 0;
}
