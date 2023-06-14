#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( std::string const & target );
	ShrubberyCreationForm( AForm const & other );

	~ShrubberyCreationForm();

	ShrubberyCreationForm& operator=( AForm const & other );

	void beExecuted( void ) const;
};

#endif /* SHRUBBERYCREATIONFORM_HPP */
