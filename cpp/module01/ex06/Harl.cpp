/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:48:14 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/27 23:02:20 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

Harl::Harl(const std::string level) {
	this->_level = this->getLevelFromString(level);
};

Harl::~Harl(void) {};

Harl::filterLevel Harl::getLevel(void) const
{
  return this->_level;
};

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

Harl::filterLevel Harl::getLevelFromString(std::string level)
{
  std::string complaintLevelArray[] = {
    "ERROR",
    "WARNING",
    "INFO",
    "DEBUG",
  };

  for (int i = 0; i < 4; i++)
  {
    if (level == complaintLevelArray[i])
      return ((filterLevel)i);
  }
  return (Harl::defaultLevel);
};

void Harl::complain( std::string level )
{
  filterLevel fLevel = this->getLevelFromString(level);

  if (fLevel <= this->_level)
  {
	  switch (fLevel)
	  {
		  case Harl::debugLevel:
		  	this->_debug();
			  break;
		  case Harl::infoLevel:
		  	this->_info();
			  break;
			case Harl::warningLevel:
					this->_warning();
					break;
			case Harl::errorLevel:
					this->_error();
					break;
			default:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	  }
  }
};
