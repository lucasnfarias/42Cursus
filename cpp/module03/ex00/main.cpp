/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:05:39 by lniehues          #+#    #+#             */
/*   Updated: 2022/04/20 19:22:53 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main( void ) {
  ClapTrap namelessCT;
  ClapTrap arnaldo("Arnaldo");

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

  return 0;
}
