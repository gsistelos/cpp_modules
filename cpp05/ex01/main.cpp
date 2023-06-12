#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main( void )
{
	Form form("Contract", 40, 20);
	Bureaucrat gguedes("gguedes", 40);
	Bureaucrat grsaiago("grsaiago", 41);

	gguedes.signForm(form);
	grsaiago.signForm(form);

	return 0;
}
