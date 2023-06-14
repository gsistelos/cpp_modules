#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm( void );
	PresidentialPardonForm( std::string const & target );
	PresidentialPardonForm( AForm const & other );

	~PresidentialPardonForm();

	PresidentialPardonForm& operator=( AForm const & other );

	void beExecuted( void ) const;
};

#endif /* PRESIDENTIALPARDONFORM_HPP */
