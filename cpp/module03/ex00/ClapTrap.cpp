/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:55:26 by lniehues          #+#    #+#             */
/*   Updated: 2022/04/01 20:05:26 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

/*
  improve messages. create help function
  [name] : [message]
*/

ClapTrap::ClapTrap( void )
  :
  _name("NamelessClapTrap"),
  _hitPoints(10),
  _energyPoints(10),
  _attackDamage(0),
  _hitPointsLimit(10),
  _energyPointsLimit(10)
{
  std::cout << "Default constructor called" << std::endl;
};

ClapTrap::ClapTrap( std::string name )
  :
  _name(name),
  _hitPoints(10),
  _energyPoints(10),
  _attackDamage(0),
  _hitPointsLimit(10),
  _energyPointsLimit(10)
{
  std::cout << "Name constructor called" << std::endl;
};


ClapTrap::ClapTrap( ClapTrap const & src )
{
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
};

ClapTrap::~ClapTrap( void )
{
  std::cout << "Destructor called" << std::endl;
};


ClapTrap & ClapTrap::operator=(ClapTrap const & rhs )
{
  std::cout << "Copy assignment operator called" << std::endl;
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

std::string ClapTrap::getName( void ) const
{
  return _name;
};

int ClapTrap::getHitPoints( void ) const
{
  return _hitPoints;
};

int ClapTrap::getEnergyPoints( void ) const
{
  return _energyPoints;
};

int ClapTrap::getAttackDamage( void ) const
{
  return _attackDamage;
};

int ClapTrap::getHitPointsLimit( void ) const
{
  return _hitPointsLimit;
};

int ClapTrap::getEnergyPointsLimit( void ) const
{
  return _energyPointsLimit;
};

void ClapTrap::attack(const std::string& target)
{
  if (_hitPoints <= 0)
    std::cout << "Hmm... it seems " << _name << " is kind of dead :/ (no hit points)" << std::endl;
  else if (_energyPoints <= 0)
    std::cout << "Well..." << _name << "ran out of energy points :(" << std::endl;
  else
  {
    _energyPoints--;
    std::cout << "ClapTrap " << _name
    << " attacks " << target
    << " causing " << _attackDamage << " points of damage!" << std::endl;
  }
};

void ClapTrap::takeDamage(unsigned int amount)
{
  // maybe don't hit if hit point equal 0
  _hitPoints = _hitPoints - amount;
  if (_hitPoints < 0)
    _hitPoints = 0;
  std::cout << "Ouch! "<< amount << " points of damage on " << _name << std::endl;
};

void ClapTrap::beRepaired(unsigned int amount)
{
  if (_hitPoints + (int)amount > _hitPointsLimit)
  {
    std::cout << _name << " can't repair above your maximum health of " << _hitPointsLimit << " points!" << std::endl;
    std::cout << "Current Hit Points: " << _hitPoints << " points" << std::endl;
    std::cout << "Possible amount of repair: " << _hitPointsLimit - _hitPoints << " points" << std::endl;
  }
  else if (_energyPoints <= 0)
    std::cout << "Well... " << _name << " ran out of energy points :(" << std::endl;
  else
  {
    _energyPoints--;
    _hitPoints += amount;
    std::cout << "Ahhh " << _name << " repaired " << amount << " points!" << std::endl;
  }
};

void ClapTrap::getStatus( void ) const
{
  std::cout << std::endl;
  std::cout << "##################" << std::endl;
  std::cout << "Name: " << _name << std::endl;
  std::cout << "Hit Points: " << _hitPoints << std::endl;
  std::cout << "Energy Points: " << _energyPoints << std::endl;
  std::cout << "Attack Damage: " << _attackDamage << std::endl;
  std::cout << "##################" << std::endl;
  std::cout << std::endl;
};


std::ostream & operator<<( std::ostream & o, ClapTrap const & c )
{
  o << c.getName();

  return o;
};
