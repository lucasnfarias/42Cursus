/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:04:02 by lniehues          #+#    #+#             */
/*   Updated: 2022/04/24 16:03:33 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FlagTrap.hpp"
#include <iostream>

FlagTrap::FlagTrap( void )
{
  _name = "NamelessFlagTrap";
  _hitPoints = 100;
  _energyPoints = 100;
  _attackDamage = 30;
  _hitPointsLimit = 100;
  _energyPointsLimit = 100;
  std::cout << "FlagTrap Default constructor called" << std::endl;
};

FlagTrap::FlagTrap( std::string name )
  :
  ClapTrap(name)
{
  _hitPoints = 100;
  _energyPoints = 100;
  _attackDamage = 30;
  _hitPointsLimit = 100;
  _energyPointsLimit = 100;
  std::cout << "FlagTrap Name constructor called" << std::endl;
};


FlagTrap::FlagTrap( FlagTrap const & src )
  :
  ClapTrap(src)
{
  std::cout << "FlagTrap Copy constructor called" << std::endl;
  *this = src;
};

FlagTrap::~FlagTrap( void )
{
  std::cout << "FlagTrap Destructor called" << std::endl;
};

FlagTrap & FlagTrap::operator=(FlagTrap const & rhs )
{
  std::cout << "FlagTrap Copy assignment operator called" << std::endl;
  if (this != &rhs)
  {
    _name = rhs.getName();
    _hitPoints = rhs.getHitPoints();
    _energyPoints = rhs.getEnergyPoints();
    _attackDamage = rhs.getAttackDamage();
    _hitPointsLimit = rhs.getHitPointsLimit();
    _energyPointsLimit = rhs.getEnergyPointsLimit();
  }
  return *this;
};

void FlagTrap::highFivesGuys(void)
{
  std::cout << "FlagTrap " << _name << " is high fiving some guys." << std::endl;
}
