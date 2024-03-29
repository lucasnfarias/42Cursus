/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:48:14 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/27 22:17:18 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

Harl::Harl(void) {};

Harl::~Harl(void) {};

void Harl::debug(void)
{
  std::cout << "[DEGUB] I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!"<< std::endl;
};

void Harl::info(void)
{
  std::cout << "[INFO] I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
};

void Harl::warning(void)
{
  std::cout << "[WARNING] I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
};

void Harl::error(void)
{
  std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now." << std::endl;
};

void Harl::complain(std::string level)
{
  methodPtr complaintFnArray[] = {
    &Harl::debug,
    &Harl::info,
    &Harl::warning,
    &Harl::error,
  };
  std::string complaintLevelArray[] = {
    "debug",
    "info",
    "warning",
    "error",
  };
  methodPtr selectedFn;

  for (int i = 0; i < 4; i++)
  {
    selectedFn = complaintFnArray[i];
    if (level == complaintLevelArray[i])
      (this->*selectedFn)();
  }
};
