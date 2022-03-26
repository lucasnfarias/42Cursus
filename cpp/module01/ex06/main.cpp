/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:52:14 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/25 22:05:45 by lniehues         ###   ########.fr       */
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
  harl.complain();
  return (0);
}
