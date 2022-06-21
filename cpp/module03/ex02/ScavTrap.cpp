/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:04:02 by lniehues          #+#    #+#             */
/*   Updated: 2022/04/24 18:33:21 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap( void )
{
  _name = "NamelessScavTrap";
  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 20;
  _hitPointsLimit = 100;
  _energyPointsLimit = 50;
  std::cout << "ScavTrap Default constructor called" << std::endl;
};

ScavTrap::ScavTrap( std::string name )
  :
  ClapTrap(name)
{
  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 20;
  _hitPointsLimit = 100;
  _energyPointsLimit = 50;
  std::cout << "ScavTrap Name constructor called" << std::endl;
};


ScavTrap::ScavTrap( ScavTrap const & src )
  :
  ClapTrap(src)
{
  std::cout << "ScavTrap Copy constructor called" << std::endl;
  *this = src;
};

ScavTrap::~ScavTrap( void )
{
  std::cout << "ScavTrap Destructor called" << std::endl;
};

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs )
{
  std::cout << "ScavTrap Copy assignment operator called" << std::endl;
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

void ScavTrap::attack(const std::string& target)
{
  if (_hitPoints <= 0)
    std::cout << "[Scavtrap] Hmm... it seems " << _name << " is kind of dead :/ (no hit points)" << std::endl;
  else if (_energyPoints <= 0)
    std::cout << "[Scavtrap] Well..." << _name << "ran out of energy points :(" << std::endl;
  else
  {
    _energyPoints--;
    std::cout << "ScavTrap " << _name
    << " attacks " << target
    << " causing " << _attackDamage << " points of damage!" << std::endl;
  }
}

void ScavTrap::guardGate()
{
  std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}
