/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:50:37 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/17 20:59:24 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Weapon.hpp"

class HumanA {

private:

  std::string _name;
  Weapon      _weapon;

public:

  HumanA( std::string name, Weapon weapon );
  ~HumanA( void );

  std::string getName( void ) const;
  void        attack( void ) const;
};
