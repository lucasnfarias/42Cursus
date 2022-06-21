/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:24:11 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/26 19:19:39 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : name(name) {}

Zombie::Zombie( void ) {
  std::cout << "A nameless zombie has become alive..." << std::endl;
}

Zombie::~Zombie( void ) {
  std::cout << "Zombie " << this->name << " died... again ;)" << std::endl;
}

void Zombie::announce( void ) {
  std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;

  return;
}

bool Zombie::setName( std::string name ) {
  if (name != "") {
    this->name = name;
    return true;
  }
  return false;
}
