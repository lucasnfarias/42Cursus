/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:48:24 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/26 19:33:51 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <string>

class Weapon
{

private:
  std::string type;

public:
  Weapon(std::string type);
  ~Weapon(void);

  const std::string& getType(void) const;
  void setType(std::string type);
};

#endif
