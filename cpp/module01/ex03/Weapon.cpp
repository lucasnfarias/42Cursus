/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:03:21 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/26 19:33:59 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {};

Weapon::~Weapon(void) {};

const std::string& Weapon::getType(void) const {
  return this->type;
};

void Weapon::setType(std::string type) {
  if (type.length() > 0)
    this->type = type;
  return;
};
