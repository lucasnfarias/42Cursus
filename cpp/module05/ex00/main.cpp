/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:56:08 by lniehues          #+#    #+#             */
/*   Updated: 2022/04/30 18:39:53 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main( void )
{
  Bureaucrat capote;
  Bureaucrat john("John", 13);

  capote.incrementGrade();
  john.decrementGrade();
  std::cout << capote;
  std::cout << john;

  Bureaucrat gregor("gregor", 150);
  Bureaucrat thomas("Thomas", 1);

  gregor.decrementGrade();
  thomas.incrementGrade();

  std::cout << gregor;
  std::cout << thomas;

  return (0);
}
