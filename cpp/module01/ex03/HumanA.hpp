/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:50:37 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/19 16:52:58 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANA_HPP
#define HUMANA_HPP
#include <string>
#include "Weapon.hpp"

class HumanA
{
private:
  std::string name;
  Weapon& weapon;

public:
  HumanA(std::string name, Weapon& weapon);
  ~HumanA(void);

  std::string getName(void) const;
  void attack(void) const;
};

#endif
