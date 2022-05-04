#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{

	public:

		RobotomyRequestForm( RobotomyRequestForm const & src );
		~RobotomyRequestForm();

		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );

    virtual void execute(Bureaucrat const & executor) const;

	private:

		RobotomyRequestForm();
};

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i );

#endif /* ******************************************** ROBOTOMYREQUESTFORM_H */
