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

	file << "          &&& &&  & &&" << std::endl;
    file << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
    file << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
    file << "   &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
    file << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
    file << "&&   && & &| &| /& & % ()& /&&" << std::endl;
    file << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
    file << "     &&     \\|||" << std::endl;
    file << "             |||" << std::endl;
    file << "             |||" << std::endl;
    file << "             |||" << std::endl;
    file << "       , -=-~  .-^- _" << std::endl;
    file << "              `" << std::endl;
    file << std::endl;
    file << "       ###" << std::endl;
    file << "      #o###" << std::endl;
    file << "    #####o###" << std::endl;
    file << "   #o#\\#|#/###" << std::endl;
    file << "    ###\\|/#o#" << std::endl;
    file << "     # }|{  #" << std::endl;
    file << "       }|{" << std::endl;
    file << std::endl;
    file << "     ccee88oo" << std::endl;
    file << "  C8O8O8Q8PoOb o8oo" << std::endl;
    file << " dOB69QO8PdUOpugoO9bD" << std::endl;
    file << "CgggbU8OU qOp qOdoUOdcb" << std::endl;
    file << "    6OuU  /p u gcoUodpP" << std::endl;
    file << "      \\\\\\//  /douUP" << std::endl;
    file << "        \\\\\\////" << std::endl;
    file << "         |||/\\" << std::endl;
    file << "         |||\\/" << std::endl;
    file << "         |||||" << std::endl;
    file << "        //||||\\" << std::endl;
}
