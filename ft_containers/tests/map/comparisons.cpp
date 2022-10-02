/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparisons.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:20:48 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/25 20:10:00 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

template <typename T1, typename T2>
void mapCompare(ft::map<T1, T2> &map1, ft::map<T1, T2> &map2)
{
  if (map1 == map2)
    std::cout << "map1 is EQUAL to map2" << std::endl;
  if (map1 != map2)
    std::cout << "map1 is NOT EQUAL to map2" << std::endl;
  if (map1 < map2)
    std::cout << "map1 is LESS THAN map2" << std::endl;
  if (map1 > map2)
    std::cout << "map1 is GREATER THAN map2" << std::endl;
  if (map1 <= map2)
    std::cout << "map1 is LESS THAN or EQUAL to map2" << std::endl;
  if (map1 >= map2)
    std::cout << "map1 is GREATER THAN or EQUAL to map2" << std::endl;

  std::cout << std::endl;
}

void  tests_comparisons()
{
  prettyPrint(SUBTITLE, "Test COMPARISONS");

  prettyPrint(DESCRIPTION, "test <, >, >=, <= comparison");

  prettyPrint(CODE_INSTRUCTIONS, "map<int,std::string> map3;");
  prettyPrint(CODE_INSTRUCTIONS, "map<int,std::string> map4;");
  ft::map<int, std::string> map3;
  ft::map<int, std::string> map4;

  map3[4] = "biru";
  map3[21] = "patati";
  map4[4] = "biru";
  map4[21] = "patati";
  map4[42] = "patata";

  printMap(map3);
  printMap(map4);
  mapCompare(map3, map4);
  mapCompare(map4, map3);

  map3[42] = "patatata";

  printMap(map3);
  printMap(map4);
  mapCompare(map3, map4);
  mapCompare(map4, map3);

  prettyPrint(DESCRIPTION, "test EQUAL comparison");

  prettyPrint(CODE_INSTRUCTIONS, "map<char,float> map1;");
  prettyPrint(CODE_INSTRUCTIONS, "map<char,float> map2;");
  ft::map<char, float> map1;
  ft::map<char, float> map2;

  prettyPrint(DESCRIPTION, "test equal comparison w/ maps same size and elements");

  map1['c'] = 42.2f;
  map1['d'] = 200.1f;
  map2['c'] = 42.2f;
  map2['d'] = 200.1f;

  printMap(map1);
  printMap(map2);
  mapCompare(map1, map2);

  prettyPrint(DESCRIPTION, "test equal comparison w/ maps same size and different element values");

  map1['e'] = 100.2f;
  map2['e'] = 1000.2f;

  printMap(map1);
  printMap(map2);
  mapCompare(map1, map2);

  prettyPrint(DESCRIPTION, "test equal comparison w/ maps different size and elements");

  map1.erase('e');

  printMap(map1);
  printMap(map2);
  mapCompare(map1, map2);
  mapCompare(map2, map1);

}
