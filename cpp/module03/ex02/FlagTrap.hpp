/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:39:32 by lniehues          #+#    #+#             */
/*   Updated: 2022/04/24 16:01:42 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

# include "ClapTrap.hpp"

class FlagTrap : public ClapTrap {
public:
  FlagTrap( void );
  FlagTrap( std::string name );
  FlagTrap( FlagTrap const & src );
  ~FlagTrap( void );

  FlagTrap & operator=( FlagTrap const & rhs );

  void highFivesGuys(void);
};

#endif
