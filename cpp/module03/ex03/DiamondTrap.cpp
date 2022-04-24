/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:04:02 by lniehues          #+#    #+#             */
/*   Updated: 2022/04/24 18:31:16 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap( void )
{
  _name = "NamelessDiamondTrap";
  ClapTrap::_name = "NamelessDiamondTrap_clap_name";
  _hitPoints = FragTrap::hitPointsInit;
  _energyPoints = ScavTrap::energyPointsInit;
  _attackDamage = FragTrap::attackDamageInit;
  _hitPointsLimit = FragTrap::hitPointsInit;
  _energyPointsLimit = ScavTrap::energyPointsInit;
  std::cout << "DiamondTrap Default constructor called" << std::endl;
};

DiamondTrap::DiamondTrap( std::string name )
  :
  ClapTrap(name),
  FragTrap(name),
  ScavTrap(name)
{
  _name = name;
  ClapTrap::_name = _name + "_clap_name";
  _hitPoints = FragTrap::hitPointsInit;
  _energyPoints = ScavTrap::energyPointsInit;
  _attackDamage = FragTrap::attackDamageInit;
  _hitPointsLimit = FragTrap::hitPointsInit;
  _energyPointsLimit = ScavTrap::energyPointsInit;
  std::cout << "DiamondTrap Name constructor called" << std::endl;
};


DiamondTrap::DiamondTrap( DiamondTrap const & src )
  :
  ClapTrap(src),
  FragTrap(src),
  ScavTrap(src)
{
  std::cout << "DiamondTrap Copy constructor called" << std::endl;
  *this = src;
};

DiamondTrap::~DiamondTrap( void )
{
  std::cout << "DiamondTrap Destructor called" << std::endl;
};

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & rhs )
{
  std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
  if (this != &rhs)
  {
    _name = rhs._name;
    ClapTrap::_name = rhs.getName();
    _hitPoints = rhs.getHitPoints();
    _energyPoints = rhs.getEnergyPoints();
    _attackDamage = rhs.getAttackDamage();
    _hitPointsLimit = rhs.getHitPointsLimit();
    _energyPointsLimit = rhs.getEnergyPointsLimit();
  }
  return *this;
};

void DiamondTrap::attack(const std::string& target)
{
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
  std::cout << "DiamondTrap " << _name << " : ClapTrap " << ClapTrap::_name << std::endl;
}
