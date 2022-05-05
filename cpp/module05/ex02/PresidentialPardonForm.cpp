#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm(std::string target)
  :
  AForm("PresidentialPardonForm", 25, 5)
{
  setTarget(target);
  std::cout << *this << std::endl;
}


PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src )
  :
  AForm(src)
{}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm() {}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i )
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

bool PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
  if (AForm::execute(executor))
  {
    std::cout << getTarget() <<" has been pardoned by Zaphod Beeblebrox." << std::endl;
    return true;
  }
  return false;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
