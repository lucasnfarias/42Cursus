/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:44:01 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/24 19:47:24 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void tests_count()
{
  prettyPrint(SUBTITLE, "Test COUNT function");

  prettyPrint(CODE_INSTRUCTIONS, "map<char, double> mymap;");
  ft::map<char, double> mymap;
  char c;

  mymap['a'] = 101.3;
  mymap['c'] = 202;
  mymap['f'] = 303.12;

  printMap(mymap);

  for (c = 'a';c < 'h';c++)
  {
    std::cout << c;
    if (mymap.count(c) > 0)
      std::cout << " is an element of mymap.\n";
    else
      std::cout << " is not an element of mymap.\n";
  }

}
