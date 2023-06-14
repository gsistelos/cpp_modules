#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm( void );
	RobotomyRequestForm( std::string const & target );
	RobotomyRequestForm( AForm const & other );

	~RobotomyRequestForm();

	RobotomyRequestForm& operator=( AForm const & other );

	void beExecuted( void ) const;
};

#endif /* ROBOTOMYREQUESTFORM_HPP */
