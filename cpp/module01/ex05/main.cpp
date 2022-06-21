/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:52:14 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/27 22:24:11 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include "Harl.hpp"

std::string commandPicker(int n)
{
  if (n == 1)
    return "debug";
  if (n == 2)
    return "info";
  if (n == 3)
    return "warning";
  if (n == 4)
    return "error";
  return "";
}

int main(void)
{
  Harl  harl;
  int n = 0;

  while (n != 5)
  {
    std::cout << "\n# Type the number of one of the commands:" << std::endl;
    std::cout << "1) debug" << std::endl;
    std::cout << "2) info" << std::endl;
    std::cout << "3) warning" << std::endl;
    std::cout << "4) error" << std::endl;
    std::cout << "5) exit" << std::endl;
    std::cout << "# Command Number: ";
    std::cin >> n;
    std::cout << "-------------" << std::endl;
	if(!std::cin)
	{
		std::cout << "Only numbers, please" << std::endl;
		std::cin.clear(); // reset failbit
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
		continue;
	}
    if (n < 1 || n > 5)
      std::cout << "I don't know that command" << std::endl;
    else
      harl.complain(commandPicker(n));
  }
  std::cout << "Bye mate :)" << std::endl;
}
