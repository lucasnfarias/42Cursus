/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 14:56:32 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/24 15:35:03 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void  tests_insert()
{
  prettyPrint(SUBTITLE, "Test INSERT function");

  prettyPrint(DESCRIPTION, "test SIMPLE VALUE insertion");

  prettyPrint(CODE_INSTRUCTIONS, "map<char,int> mapTest;");
  ft::map<char, int> mapTest;

  prettyPrint(CODE_INSTRUCTIONS, "mapTest.insert(ft::make_pair('z', 32));");
  mapTest.insert(ft::make_pair('z', 32));
  prettyPrint(CODE_INSTRUCTIONS, "mapTest.insert(ft::pair<char, int>('a', 101));");
  mapTest.insert(ft::pair<char, int>('a', 101));

  ft::pair<ft::map<char,int>::iterator, bool> result;

  prettyPrint(CODE_INSTRUCTIONS, "result = mapTest.insert(ft::pair<char, int>('a', 21));");
  result = mapTest.insert(ft::pair<char, int>('a', 21));

  if (result.second)
    std::cout << "mapTest inserted 'a' as 21 successfully" << std::endl;
  else
    std::cout << "mapTest 'a' insertion was NOT successful because 'a' was already filled" << std::endl;
  std::cout << "result: mapTest[" << result.first->first << "] = " << result.first->second << std::endl;

  prettyPrint(DESCRIPTION, "test HINT insertion");

  prettyPrint(CODE_INSTRUCTIONS, "ft::map<char,int>::iterator it = mapTest.begin();");
  ft::map<char,int>::iterator it = mapTest.begin();

  prettyPrint(CODE_INSTRUCTIONS, "mapTest.insert(it, ft::pair<char,int>('b', -12));");
  mapTest.insert(it, ft::pair<char,int>('b', -12)); // a preceding b key value so hint is helpful to insert
  prettyPrint(CODE_INSTRUCTIONS, "mapTest.insert(it, ft::make_pair('t', -12));");
  mapTest.insert(it, ft::make_pair('t', -12)); // a DOES NOT preceds b key value so hint is NOT helpful to insert

  printMap(mapTest, true, "mapTest");

  prettyPrint(DESCRIPTION, "test ITERATORS insertion");

  prettyPrint(CODE_INSTRUCTIONS, "ft::map<char, int> mapTestIterInserted;");
  ft::map<char, int> mapTestIterInserted;

  prettyPrint(CODE_INSTRUCTIONS, "mapTestIterInserted.insert(mapTest.begin(), --mapTest.end());");
  mapTestIterInserted.insert(mapTest.begin(), --mapTest.end());

  printMap(mapTestIterInserted, true, "mapTestIterInserted");
}
