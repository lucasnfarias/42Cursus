/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:05:39 by lniehues          #+#    #+#             */
/*   Updated: 2022/04/14 18:59:12 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main( void ) {
  ClapTrap namelessCT;
  ClapTrap ct("Arnaldo");

  namelessCT.attack("Arnaldo");
  ct.attack("Someone");
  ct.takeDamage(2);
  ct.beRepaired(3);
  ct.beRepaired(2);
  ct.takeDamage(10);
  ct.attack("Someone");
  namelessCT.takeDamage(5);

  ct.getStatus();
  namelessCT.getStatus();

  return 0;
}
