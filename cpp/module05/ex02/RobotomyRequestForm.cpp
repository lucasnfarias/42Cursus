#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )
{
	o
  << i.getName()
  << ", form sign grade "
  << i.getSignGrade()
  << ", execution grade "
  << i.getExecutionGrade()
  << " and is"
  << (i.getIsSigned() ? " " : " NOT ")
  << "signed."
  << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void  RobotomyRequestForm::execute(Bureaucrat const & executor) const
{}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
