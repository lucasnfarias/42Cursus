/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:24:11 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/16 22:07:32 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : name(name) {}

Zombie::Zombie( void ) {
  std::cout << "A nameless zombie has been become alive..." << std::endl;
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
