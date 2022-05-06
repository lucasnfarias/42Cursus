/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:32:44 by lniehues          #+#    #+#             */
/*   Updated: 2022/05/05 20:58:48 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

std::string Intern::_formNamesList[3] = {
  "shrubbery creation", "robotomy request", "presidential pardon"
};

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
  std::cout << "Intern created!" << std::endl;
}

Intern::Intern(Intern const& src)
{
	*this = src;
	std::cout << "Intern copied" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
  std::cout << "Intern destroyed!" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

std::ostream &			operator<<( std::ostream & o, Intern const & i )
{
  (void)i;
	o << "I am just a faceless intern :(";
	return o;
}

Intern & Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return (*this);
}


/*
** --------------------------------- METHODS ----------------------------------
*/

AForm*  Intern::_createShrubberyCreationForm(std::string target)
{
  return new ShrubberyCreationForm(target);
}

AForm*  Intern::_createRobotomyRequestForm(std::string target)
{
  return new RobotomyRequestForm(target);
}

AForm*  Intern::_createPresidentialPardonForm(std::string target)
{
  return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string formTarget)
{
  AForm* (Intern::*formCreatorsList[3])(std::string target) = {
    &Intern::_createShrubberyCreationForm,
    &Intern::_createRobotomyRequestForm,
    &Intern::_createPresidentialPardonForm
  };
  for(int i = 0; i < 3; i++)
	{
		if(formName == Intern::_formNamesList[i])
		{
			std::cout << "Intern creates " << formName << " form" << std::endl;
			return ((this->*formCreatorsList[i])(formTarget));
		}
	}
  std::cerr << formName << " does NOT exists >:*" << std::endl;
  return (NULL);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
