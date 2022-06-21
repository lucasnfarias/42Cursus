/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:56:08 by lniehues          #+#    #+#             */
/*   Updated: 2022/05/04 19:09:04 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{
  Bureaucrat capote;
  Bureaucrat john("John", 13);
  Form defaultForm;
  Form irpf("IRPF", 73, 73);

  capote.incrementGrade();
  john.decrementGrade();

  std::cout << capote;
  std::cout << john;

  capote.signForm(defaultForm);
  capote.signForm(irpf);

  std::cout << defaultForm;
  std::cout << irpf;

  john.signForm(irpf);

  std::cout << irpf;

  return (0);
}
