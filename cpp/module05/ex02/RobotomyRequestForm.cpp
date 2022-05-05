#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm(std::string target)
  :
  AForm("RobotomyRequestForm", 72, 45)
{
  setTarget(target);
  std::cout << *this << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src )
  :
  AForm(src)
{}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm() {}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )
{
  o
  << "---" << std::endl
  << i.getName()
  << " Form"
  << std::endl
  << "# Sign grade: "
  << i.getSignGrade()
  << std::endl
  << "# Execution grade: "
  << i.getExecutionGrade()
  << std::endl
  << "# Signed: "
  << (i.getIsSigned() ? "YES" : "NO")
  << std::endl
  << "# Target: "
  << i.getTarget()
  << std::endl << "---" << std::endl
  << std::endl;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

bool RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
  if (AForm::execute(executor))
  {
    std::cout << "BRRRRRRRRRRRRRR BRRRRRRRRR (supposedly drilling noises)" << std::endl;
    std::cout << getTarget() <<" has been robotomized successfully 50% of the time" << std::endl;
    return true;
  }
  return false;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
