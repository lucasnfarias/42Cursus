/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:39:32 by lniehues          #+#    #+#             */
/*   Updated: 2022/04/24 18:29:36 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
  ScavTrap( void );
  ScavTrap( std::string name );
  ScavTrap( ScavTrap const & src );
  ~ScavTrap( void );

  ScavTrap & operator=( ScavTrap const & rhs );

  void attack(const std::string& target);
  void guardGate();

protected:
  static int hitPointsInit;
  static int energyPointsInit;
  static int attackDamageInit;
};

#endif
