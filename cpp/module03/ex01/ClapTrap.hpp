/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:43:12 by lniehues          #+#    #+#             */
/*   Updated: 2022/04/01 19:53:11 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap {

public:
  ClapTrap( void );
  ClapTrap( std::string name );
  ClapTrap( ClapTrap const & src );
  ~ClapTrap( void );

  ClapTrap & operator=( ClapTrap const & rhs );

  std::string getName( void ) const;
  int getHitPoints( void ) const;
  int getEnergyPoints( void ) const;
  int getAttackDamage( void ) const;
  int getHitPointsLimit( void ) const;
  int getEnergyPointsLimit( void ) const;

  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  void getStatus( void ) const;

protected:
  std::string _name;
  int _hitPoints;
  int _energyPoints;
  int _attackDamage;
  int _hitPointsLimit;
  int _energyPointsLimit;
};

std::ostream & operator<<( std::ostream & o, ClapTrap const & c );

#endif
