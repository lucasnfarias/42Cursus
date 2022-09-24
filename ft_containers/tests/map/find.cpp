/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:24:23 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/24 19:32:54 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void tests_find()
{
  prettyPrint(SUBTITLE, "Test FIND function");

  prettyPrint(CODE_INSTRUCTIONS, "ft::map<char,int> mymap;");
  prettyPrint(CODE_INSTRUCTIONS, "ft::map<char,int>::iterator it;");
  ft::map<char,int> mymap;
  ft::map<char,int>::iterator it;

  prettyPrint(CODE_INSTRUCTIONS, "mymap['a'] = 50;");
  prettyPrint(CODE_INSTRUCTIONS, "mymap['b'] = 100;");
  prettyPrint(CODE_INSTRUCTIONS, "mymap['c'] = 150;");
  prettyPrint(CODE_INSTRUCTIONS, "mymap['d'] = 200;");

  mymap['a'] = 50;
  mymap['b'] = 100;
  mymap['c'] = 150;
  mymap['d'] = 200;

  prettyPrint(CODE_INSTRUCTIONS, "it = mymap.find('e');");
  it = mymap.find('e');

  if (it == mymap.end()) std::cout << "element key 'e' not found!" << std::endl;

  std::cout << "elements in mymap:" << std::endl;
  std::cout << "a => " << mymap.find('a')->second << std::endl;
  std::cout << "b => " << mymap.find('b')->second << std::endl;
  std::cout << "c => " << mymap.find('c')->second << std::endl;
  std::cout << "d => " << mymap.find('d')->second << std::endl;

  prettyPrint(CODE_INSTRUCTIONS, "ft::map<char,int>::const_iterator itConst;");
  ft::map<char,int>::const_iterator itConst;

  prettyPrint(CODE_INSTRUCTIONS, "mymap.erase('b')");
  mymap.erase('b');

  prettyPrint(CODE_INSTRUCTIONS, "itConst = mymap.find('b');");
  itConst = mymap.find('b');

  if (itConst == mymap.end()) std::cout << "element key 'b' not found!" << std::endl;

}
