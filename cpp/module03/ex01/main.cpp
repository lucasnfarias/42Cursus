/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:05:39 by lniehues          #+#    #+#             */
/*   Updated: 2022/04/24 15:54:36 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

int main( void ) {
  ClapTrap namelessCT;
  ClapTrap arnaldo("Arnaldo");
  ScavTrap namelessST;
  ScavTrap creyson("Creyson");

  namelessCT.attack("Arnaldo");
  arnaldo.attack("Someone");
  arnaldo.takeDamage(2);
  arnaldo.beRepaired(3);
  arnaldo.beRepaired(2);
  arnaldo.takeDamage(10);
  arnaldo.attack("Someone");
  namelessCT.takeDamage(5);

  arnaldo.getStatus();
  namelessCT.getStatus();

  namelessST.attack("Arnaldo");
  creyson.attack("Someone");
  creyson.takeDamage(2);
  creyson.beRepaired(3);
  creyson.beRepaired(2);
  creyson.takeDamage(10);
  creyson.attack("Someone");
  namelessST.takeDamage(5);

  namelessST.guardGate();
  creyson.guardGate();

  creyson.getStatus();
  namelessST.getStatus();

  arnaldo = creyson;
  arnaldo.getStatus();

  std::cout << "Check std::cout -> " << namelessCT << std::endl;
  std::cout << "Check std::cout -> " << arnaldo << std::endl;

  return 0;
}
