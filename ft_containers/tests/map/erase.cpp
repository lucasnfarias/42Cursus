/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:14:30 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/24 18:25:13 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void  tests_erase()
{
  prettyPrint(SUBTITLE, "Test ERASE function");

  prettyPrint(CODE_INSTRUCTIONS, "ft::map<char,int> mapTest;");
  prettyPrint(CODE_INSTRUCTIONS, "ft::map<char,int>::iterator it;");

  ft::map<char, int> mapTest;
  ft::map<char,int>::iterator it;

  prettyPrint(CODE_INSTRUCTIONS, "mapTest['a'] = 10;");
  prettyPrint(CODE_INSTRUCTIONS, "mapTest['b'] = 20;");
  prettyPrint(CODE_INSTRUCTIONS, "mapTest['c'] = 30;");
  prettyPrint(CODE_INSTRUCTIONS, "mapTest['d'] = 40;");
  prettyPrint(CODE_INSTRUCTIONS, "mapTest['e'] = 50;");
  prettyPrint(CODE_INSTRUCTIONS, "mapTest['f'] = 60;");

  mapTest['a'] = 10;
  mapTest['b'] = 20;
  mapTest['c'] = 30;
  mapTest['d'] = 40;
  mapTest['e'] = 50;
  mapTest['f'] = 60;

  prettyPrint(DESCRIPTION, "test erasing by iterator");
  prettyPrint(CODE_INSTRUCTIONS, "it = mapTest.find('b');");
  prettyPrint(CODE_INSTRUCTIONS, "mapTest.erase(it);");

  it = mapTest.find('b');
  mapTest.erase(it);

  prettyPrint(DESCRIPTION, "test erasing by key");
  prettyPrint(CODE_INSTRUCTIONS, "mapTest.erase('c');");

  mapTest.erase('c');

  prettyPrint(DESCRIPTION, "test erasing by range");
  prettyPrint(CODE_INSTRUCTIONS, "it = mapTest.find('e');");
  prettyPrint(CODE_INSTRUCTIONS, "mapTest.erase(it, mapTest.end());");

  it = mapTest.find('e');
  mapTest.erase(it, mapTest.end());

  printMap(mapTest, true, "mapTest");

}
