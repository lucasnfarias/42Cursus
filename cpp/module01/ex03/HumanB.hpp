/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:50:50 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/17 21:03:00 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Weapon.hpp"

class HumanB {

private:

  std::string _name;
  Weapon      _weapon;

public:

  HumanB( std::string name );
  ~HumanB( void );

  std::string getName( void ) const;
  void        setWeapon( Weapon weapon );
  void        attack( void ) const;
};
