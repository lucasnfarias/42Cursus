/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:56:08 by lniehues          #+#    #+#             */
/*   Updated: 2022/05/05 20:56:40 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main( void )
{
  Intern someRandomIntern;
  AForm* scf;
  AForm* rrf;
  AForm* ppf;
  Bureaucrat bob("Bob", 5);

  scf = someRandomIntern.makeForm("shrubbery creation", "Mads");
  rrf = someRandomIntern.makeForm("robotomy request", "Bender");
  ppf = someRandomIntern.makeForm("presidential pardon", "Poodle");
  someRandomIntern.makeForm("random", "Top");

  bob.decrementGrade();
  std::cout << bob;
  std::cout << "---------------" << std::endl;
  bob.signForm(*scf);
  bob.signForm(*rrf);
  bob.signForm(*ppf);
  std::cout << "---------------" << std::endl;
  bob.executeForm(*scf);
  bob.executeForm(*rrf);
  bob.executeForm(*ppf);
  std::cout << "---------------" << std::endl;

  delete scf;
  delete rrf;
  delete ppf;

  return (0);
}
