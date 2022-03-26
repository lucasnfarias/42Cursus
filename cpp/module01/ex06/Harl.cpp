/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:48:14 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/25 22:04:44 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

Harl::Harl(const std::string level) : _level(level) {};

Harl::~Harl(void) {};

void Harl::_messageBuilder(std::string level, std::string message)
{
  std::cout
  << level
  << std::endl
  << message
  << std::endl
  << std::endl;
}

void Harl::_debug(void)
{
  this->_messageBuilder(
    "[DEGUB]",
    "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!"
  );
};

void Harl::_info(void)
{
  this->_messageBuilder(
    "[INFO]",
    "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
  );
};

void Harl::_warning(void)
{
  this->_messageBuilder(
    "[WARNING]",
    "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
  );
};

void Harl::_error(void)
{
  this->_messageBuilder(
    "[ERROR]",
    "This is unacceptable! I want to speak to the manager now."
  );
};

void Harl::complain( void )
{
  void (Harl::*complaintFnArray[])(void) = {
    &Harl::_debug,
    &Harl::_info,
    &Harl::_warning,
    &Harl::_error,
  };
  std::string complaintLevelArray[] = {
    "DEBUG",
    "INFO",
    "WARNING",
    "ERROR",
  };
  int fnIndex = -1;

  for (int i = 0; i < 4; i++)
  {
    if (this->_level == complaintLevelArray[i])
      fnIndex = i;
  }

  if (fnIndex == -1)
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
  else {
    for (int j = fnIndex; j < 4; j++)
    {
      (this->*complaintFnArray[j])();
    }
  }
};
