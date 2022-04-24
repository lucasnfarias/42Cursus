/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:05:39 by lniehues          #+#    #+#             */
/*   Updated: 2022/04/24 16:01:56 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FlagTrap.hpp"

int main( void ) {
  ClapTrap namelessCT;
  ClapTrap arnaldo("Arnaldo");
  ScavTrap xandi("Xandi");
  FlagTrap namelessFT;
  FlagTrap creyson("Creyson");

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

  xandi.guardGate();

  namelessFT.attack("Arnaldo");
  creyson.attack("Someone");
  creyson.takeDamage(2);
  creyson.beRepaired(3);
  creyson.beRepaired(2);
  creyson.takeDamage(10);
  creyson.attack("Someone");
  namelessFT.takeDamage(5);

  namelessFT.highFivesGuys();
  creyson.highFivesGuys();

  creyson.getStatus();
  namelessFT.getStatus();

  arnaldo = creyson;
  arnaldo.getStatus();

  std::cout << "Check std::cout -> " << namelessCT << std::endl;
  std::cout << "Check std::cout -> " << arnaldo << std::endl;

  return 0;
}
