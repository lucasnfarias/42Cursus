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
    this->_name = rhs.getName();
    this->_hitPoints = rhs.getHitPoints();
    this->_energyPoints = rhs.getEnergyPoints();
    this->_attackDamage = rhs.getAttackDamage();
    this->_hitPointsLimit = rhs.getHitPointsLimit();
    this->_energyPointsLimit = rhs.getEnergyPointsLimit();
  }
  return *this;
};

std::string ClapTrap::getName( void ) const
{
  return this->_name;
};

int ClapTrap::getHitPoints( void ) const
{
  return this->_hitPoints;
};

int ClapTrap::getEnergyPoints( void ) const
{
  return this->_energyPoints;
};

int ClapTrap::getAttackDamage( void ) const
{
  return this->_attackDamage;
};

int ClapTrap::getHitPointsLimit( void ) const
{
  return this->_hitPointsLimit;
};

int ClapTrap::getEnergyPointsLimit( void ) const
{
  return this->_energyPointsLimit;
};

void ClapTrap::attack(const std::string& target)
{
  if (this->_hitPoints <= 0)
    std::cout << "Hmm... it seems " << this->_name << " is kind of dead :/ (no hit points)" << std::endl;
  else if (this->_energyPoints <= 0)
    std::cout << "Well..." << this->_name << "ran out of energy points :(" << std::endl;
  else
  {
    this->_energyPoints--;
    std::cout << "ClapTrap " << this->_name
    << " attacks " << target
    << " causing " << this->_attackDamage << " points of damage!" << std::endl;
  }
};

void ClapTrap::takeDamage(unsigned int amount)
{
  // maybe don't hit if hit point equal 0
  this->_hitPoints = this->_hitPoints - amount;
  if (this->_hitPoints < 0)
    this->_hitPoints = 0;
  std::cout << "Ouch! "<< amount << " points of damage on " << this->_name << std::endl;
};

void ClapTrap::beRepaired(unsigned int amount)
{
  if (this->_hitPoints + (int)amount > this->_hitPointsLimit)
  {
    std::cout << this->_name << " can't repair above your maximum health of " << this->_hitPointsLimit << " points!" << std::endl;
    std::cout << "Current Hit Points: " << this->_hitPoints << " points" << std::endl;
    std::cout << "Possible amount of repair: " << this->_hitPointsLimit - this->_hitPoints << " points" << std::endl;
  }
  else if (this->_energyPoints <= 0)
    std::cout << "Well... " << this->_name << " ran out of energy points :(" << std::endl;
  else
  {
    this->_energyPoints--;
    std::cout << "Ahhh " << this->_name << " repaired " << amount << " points!" << std::endl;
  }
};

void ClapTrap::getStatus( void ) const
{
  std::cout << "##################" << std::endl;
  std::cout << "Name: " << this->_name << std::endl;
  std::cout << "Hit Points: " << this->_hitPoints << std::endl;
  std::cout << "Energy Points: " << this->_energyPoints << std::endl;
  std::cout << "Attack Damage: " << this->_attackDamage << std::endl;
  std::cout << "##################" << std::endl;
};


std::ostream & operator<<( std::ostream & o, ClapTrap const & c )
{
  o << c.getName();

  return o;
};
