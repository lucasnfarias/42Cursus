/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:56:08 by lniehues          #+#    #+#             */
/*   Updated: 2022/05/05 19:15:40 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

int main( void )
{
  Bureaucrat creyson("Creyson", 145);
  Bureaucrat john("John", 44);
  Bureaucrat horacio("Horacio", 4);
  ShrubberyCreationForm scf("Nave Mãe 42"); // sign 145, exec 137
  RobotomyRequestForm rqf("Lady Gaga"); // sign 72, exec 45
  PresidentialPardonForm ppf("Mads Mikkelsen"); // sign 25, exec 5

  std::cout << creyson;
  std::cout << john;
  std::cout << horacio;
  std::cout << "---------------" << std::endl;

  // Error example - trying to execute before signing
  creyson.executeForm(scf);

  std::cout << "---------------" << std::endl;
  creyson.signForm(scf);
  creyson.signForm(rqf);
  creyson.signForm(ppf);
  std::cout << "---------------" << std::endl;
  creyson.executeForm(scf);
  creyson.executeForm(rqf);
  creyson.executeForm(ppf);
  std::cout << "---------------" << std::endl;
  // john.signForm(scf); - no need to sign because Creyson signed
  john.signForm(rqf);
  john.signForm(ppf);
  std::cout << "---------------" << std::endl;
  john.executeForm(scf);
  john.executeForm(rqf);
  john.executeForm(ppf);
  std::cout << "---------------" << std::endl;
  // horacio.signForm(ppf); - no need to sign because Creyson signed
  // horacio.signForm(ppf); - no need to sign because John signed
  horacio.signForm(ppf);
  std::cout << "---------------" << std::endl;
  horacio.executeForm(scf);
  horacio.executeForm(rqf);
  horacio.executeForm(ppf);
  std::cout << "---------------" << std::endl;
  std::cout << scf;
  std::cout << rqf;
  std::cout << ppf;

  return (0);
}
