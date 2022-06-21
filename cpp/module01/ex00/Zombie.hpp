/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:21:23 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/25 21:45:31 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>

class Zombie
{

private:

  std::string name;

public:

  Zombie( std::string name );
  ~Zombie( void );

  void announce( void );
};

Zombie* newZombie( std::string name );

void randomChump( std::string name );

#endif
