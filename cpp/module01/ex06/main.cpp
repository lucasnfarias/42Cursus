/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:52:14 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/27 23:02:46 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cerr << "I need one argument mate :)" << std::endl;
    return (1);
  }
  Harl harl(argv[1]);
  harl.complain("DEBUG");
  harl.complain("INFO");
  harl.complain("WARNING");
  harl.complain("ERROR");
  if (harl.getLevel() == Harl::defaultLevel)
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
  return (0);
}
