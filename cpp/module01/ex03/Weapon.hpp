/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:48:24 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/19 16:53:06 by lniehues         ###   ########.fr       */
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

  std::string getType(void) const;
  void setType(std::string type);
};

#endif
