/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:12:41 by lniehues          #+#    #+#             */
/*   Updated: 2022/04/24 18:12:45 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {

private:
  std::string _name;

public:
  DiamondTrap( void );
  DiamondTrap( std::string name );
  DiamondTrap( DiamondTrap const & src );
  ~DiamondTrap( void );

  DiamondTrap & operator=( DiamondTrap const & rhs );

  void attack(const std::string& target);
  void whoAmI();
};

#endif
