/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:28:11 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/16 22:08:41 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main( void )
{
  Zombie* _zombieHorde = zombieHorde(21, "Bob");

  for(int i = 0; i < 21; i++) {
    std::cout << "Zombie " << i + 1 << " :: ";
    _zombieHorde[i].announce();
  }

  delete [] _zombieHorde;

  return (0);
}
