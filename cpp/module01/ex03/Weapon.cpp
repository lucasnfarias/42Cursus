/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:03:21 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/19 16:53:13 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {};

Weapon::~Weapon(void) {};

std::string Weapon::getType(void) const {
  return this->type;
};

void Weapon::setType(std::string type) {
  if (type.length() > 0)
    this->type = type;
  return;
};
