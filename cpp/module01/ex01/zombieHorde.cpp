/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:32:13 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/16 22:00:45 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
  Zombie* zombieHorde = new Zombie[N];

  for(int i = 0; i < N; i++)
  {
    zombieHorde[i].setName(name);
  }

  return zombieHorde;
}
