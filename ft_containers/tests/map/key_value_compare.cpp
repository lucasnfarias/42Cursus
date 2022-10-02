/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_value_compare.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:56:10 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/24 19:06:34 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void  tests_key_value_compare()
{
  prettyPrint(SUBTITLE, "Test KEY VALUE COMPARE function");

  prettyPrint(DESCRIPTION, "test key compare");

  ft::map<char, int> testMap;
  ft::map<char,int>::key_compare myComp = testMap.key_comp();

  testMap['c'] = 201;
  testMap['a'] = 503;
  testMap['z'] = 705;

  std::cout << "testMap contains:\n";

  char highest = testMap.rbegin()->first;     // key value of last element

  ft::map<char,int>::iterator it = testMap.begin();

  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( myComp((*it++).first, highest) );

  prettyPrint(DESCRIPTION, "test value compare");

  std::cout << std::endl;

  ft::map<char,int> mymap;

  mymap['x'] = 1001;
  mymap['y'] = 2002;
  mymap['z'] = 3003;

  std::cout << "mymap contains:\n";

  ft::pair<char,int> highestContent = *mymap.rbegin();          // last element

  ft::map<char,int>::iterator it2 = mymap.begin();
  do {
    std::cout << it2->first << " => " << it2->second << '\n';
  } while ( mymap.value_comp()(*it2++, highestContent) );
}
