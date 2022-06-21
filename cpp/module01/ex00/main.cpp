/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:28:11 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/15 21:58:49 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main(void)
{

  std::cout << "Creating zombie Pepe manually..." << std::endl;
  {
    Zombie pepe = Zombie("Pepe");

    pepe.announce();
  }
  std::cout << std::endl;

  std::cout << "Creating zombie Creyson on heap..." << std::endl;
  {
    Zombie *creyson = newZombie("Creyson");

    creyson->announce();

    delete creyson;
  }
  std::cout << std::endl;

  std::cout << "Creating zombie Arnaldo on stack..." << std::endl;
  {
    randomChump("Arnaldo");
  }

  return (0);
}
