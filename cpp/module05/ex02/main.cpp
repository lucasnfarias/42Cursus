/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:56:08 by lniehues          #+#    #+#             */
/*   Updated: 2022/05/04 21:31:08 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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

  return (0);
}
