/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:39:32 by lniehues          #+#    #+#             */
/*   Updated: 2022/04/24 16:26:17 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
  FragTrap( void );
  FragTrap( std::string name );
  FragTrap( FragTrap const & src );
  ~FragTrap( void );

  FragTrap & operator=( FragTrap const & rhs );

  void highFivesGuys(void);
};

#endif
