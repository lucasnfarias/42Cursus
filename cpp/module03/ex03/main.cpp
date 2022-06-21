/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:05:39 by lniehues          #+#    #+#             */
/*   Updated: 2022/04/24 18:10:51 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

int main( void ) {
  DiamondTrap namelessDT;
  DiamondTrap creyson("Creyson");
  DiamondTrap namelessDT2(creyson);

  namelessDT2.whoAmI();

  creyson.getStatus();
  namelessDT.getStatus();

  namelessDT.attack("Arnaldo");
  creyson.attack("Someone");
  creyson.takeDamage(2);
  creyson.beRepaired(3);
  creyson.beRepaired(2);
  creyson.takeDamage(10);
  creyson.attack("Someone");
  namelessDT.takeDamage(5);

  creyson.guardGate();
  namelessDT.guardGate();

  creyson.highFivesGuys();
  namelessDT.highFivesGuys();

  creyson.whoAmI();
  namelessDT.whoAmI();

  creyson.getStatus();
  namelessDT.getStatus();

  std::cout << "Check std::cout -> " << creyson << std::endl;
  std::cout << "Check std::cout -> " << namelessDT << std::endl;

  return 0;
}
