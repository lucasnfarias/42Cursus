/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 15:04:41 by lniehues          #+#    #+#             */
/*   Updated: 2022/05/07 15:49:40 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "TypeConverter.hpp"

int main(int argc, char** argv)
{
  if (argc == 1)
  {
    std::cerr << "Error: no argument" << std::endl;
  }
  else if (argc > 2)
  {
    std::cerr << "Error: too many arguments" << std::endl;
  }
  else
  {
    TypeConverter converter;

    converter.convertAll(argv[1]);
  }

  return 0;
}
