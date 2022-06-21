/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:04:02 by lniehues          #+#    #+#             */
/*   Updated: 2022/04/24 18:28:44 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int FragTrap::hitPointsInit = 100;
int FragTrap::energyPointsInit = 100;
int FragTrap::attackDamageInit = 30;

FragTrap::FragTrap( void )
{
  _name = "NamelessFlagTrap";
  _hitPoints = FragTrap::hitPointsInit;
  _energyPoints = FragTrap::energyPointsInit;
  _attackDamage = FragTrap::attackDamageInit;
  _hitPointsLimit = FragTrap::hitPointsInit;
  _energyPointsLimit = FragTrap::energyPointsInit;
  std::cout << "FragTrap Default constructor called" << std::endl;
};

FragTrap::FragTrap( std::string name )
  :
  ClapTrap(name)
{
  _hitPoints = 100;
  _energyPoints = 100;
  _attackDamage = 30;
  _hitPointsLimit = 100;
  _energyPointsLimit = 100;
  std::cout << "FragTrap Name constructor called" << std::endl;
};


FragTrap::FragTrap( FragTrap const & src )
  :
  ClapTrap(src)
{
  std::cout << "FragTrap Copy constructor called" << std::endl;
  *this = src;
};

FragTrap::~FragTrap( void )
{
  std::cout << "FragTrap Destructor called" << std::endl;
};

FragTrap & FragTrap::operator=(FragTrap const & rhs )
{
  std::cout << "FragTrap Copy assignment operator called" << std::endl;
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

void FragTrap::highFivesGuys(void)
{
  std::cout << "FragTrap " << _name << " is high fiving some guys." << std::endl;
}
