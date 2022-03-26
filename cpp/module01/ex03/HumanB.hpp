/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:50:50 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/25 21:45:12 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <string>
# include "Weapon.hpp"

class HumanB
{
private:
  std::string name;
  Weapon* weapon;

public:
  HumanB(std::string name);
  ~HumanB(void);

  std::string getName(void) const;
  void setWeapon(Weapon& newWeapon);
  void attack(void) const;
};

#endif
