/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:39:32 by lniehues          #+#    #+#             */
/*   Updated: 2022/04/24 13:38:42 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
  ScavTrap( void );
  ScavTrap( std::string name );
  ScavTrap( ScavTrap const & src );
  ~ScavTrap( void );

  ScavTrap & operator=( ScavTrap const & rhs );

  void attack(const std::string& target);
  void guardGate();
};

#endif
