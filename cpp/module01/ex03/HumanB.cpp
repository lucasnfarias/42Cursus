/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:34:35 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/19 16:52:42 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

HumanB::~HumanB(void) {}

std::string HumanB::getName(void) const
{
  return this->name;
}

void HumanB::setWeapon(Weapon& newWeapon)
{
  if (newWeapon.getType() == "") {
    std::cout << "can't set an empty weapon :(" << std::endl;
    return;
  }
  this->weapon = &newWeapon;
  return;
}

void HumanB::attack(void) const
{
  std::cout << this->name << " attacks with their ";

  if (!this->weapon)
    std::cout << "bare hands (because he doesn't have a weapon)" << std::endl;
  else
    std::cout << this->weapon->getType() << std::endl;

  return;
}
