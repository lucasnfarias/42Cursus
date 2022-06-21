/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:34:35 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/19 16:52:19 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {}

HumanA::~HumanA(void) {}

std::string HumanA::getName(void) const
{
  return this->name;
}

void HumanA::attack(void) const
{
  std::cout
      << this->name
      << " attacks with their "
      << this->weapon.getType()
      << std::endl;

  return;
}
