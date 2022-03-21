/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:52:14 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/21 20:09:26 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
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
  int n;

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
    if (n < 1 || n > 5)
      std::cout << "I don't know that command" << std::endl;
    else
      harl.complain(commandPicker(n));
  }
  std::cout << "Bye mate :)" << std::endl;
}
