#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main( void )
{
	Intern intern;

	AForm* shrubbery = intern.makeForm("ShrubberyCreationForm", "home");
	AForm* robotomy = intern.makeForm("RobotomyRequestForm", "rob");
	AForm* presidential = intern.makeForm("PresidentialPardonForm", "press");

	AForm* test = intern.makeForm("TestForm", "test");

	Bureaucrat gguedes("gguedes", 1);

	gguedes.executeForm(*shrubbery);
	gguedes.executeForm(*robotomy);
	gguedes.executeForm(*presidential);

	if (test != NULL)
		gguedes.executeForm(*test);
	else
		std::cout << "TestForm is NULL, you will get a segfault dereferencing a NULL pointer" << std::endl;

	return 0;
}
