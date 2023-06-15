#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main( void )
{
	Intern intern;

	AForm* shrubbery = intern.makeForm("shrubbery creation", "home");
	AForm* robotomy = intern.makeForm("robotomy request", "rob");
	AForm* presidential = intern.makeForm("presidential pardon", "press");

	AForm* test = intern.makeForm("test", "test");

	Bureaucrat gguedes("gguedes", 1);

	gguedes.executeForm(*shrubbery);
	gguedes.executeForm(*robotomy);
	gguedes.executeForm(*presidential);

	gguedes.signForm(*shrubbery);
	gguedes.signForm(*robotomy);
	gguedes.signForm(*presidential);

	gguedes.executeForm(*shrubbery);
	gguedes.executeForm(*robotomy);
	gguedes.executeForm(*presidential);

	if (test != NULL)
		gguedes.executeForm(*test);
	else
		std::cout << "TestForm is NULL, you will get a segfault dereferencing a NULL pointer" << std::endl;

	return 0;
}
