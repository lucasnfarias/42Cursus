/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:20:48 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/24 13:31:47 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void  tests_iterators()
{
  prettyPrint(SUBTITLE, "Test ITERATORS function");

  prettyPrint(CODE_INSTRUCTIONS, "ft::map<char,int> myMap;");
  ft::map<char, int> myMap;

  prettyPrint(CODE_INSTRUCTIONS, "myMap['g'] = 42;");
  myMap['g'] = 42;
  prettyPrint(CODE_INSTRUCTIONS, "myMap['a'] = 21;");
  myMap['a'] = 21;
  prettyPrint(CODE_INSTRUCTIONS, "myMap['z'] = 8;");
  myMap['z'] = 8;
  prettyPrint(CODE_INSTRUCTIONS, "myMap['b'] = 42;");
  myMap['b'] = 42;
  prettyPrint(CODE_INSTRUCTIONS, "myMap['t'] = -2;");
  myMap['t'] = -2;

  prettyPrint(CODE_INSTRUCTIONS, "for (ft::map<char, int>::iterator it = myMap.begin(); it != myMap.end(); it++)");
  for (ft::map<char, int>::iterator it = myMap.begin(); it != myMap.end(); it++)
    std::cout << it->first << ", " << it->second << std::endl;

  prettyPrint(CODE_INSTRUCTIONS, "for (ft::map<char, int>::reverse_iterator it = myMap.rbegin(); it != myMap.rend(); it++)");
  for (ft::map<char, int>::reverse_iterator it = myMap.rbegin(); it != myMap.rend(); it++)
    std::cout << it->first << ", " << it->second << std::endl;

  prettyPrint(CODE_INSTRUCTIONS, "for (ft::map<char, int>::const_iterator constIt = myMap.begin(); constIt != myMap.end(); constIt++)");
  for (ft::map<char, int>::const_iterator constIt = myMap.begin(); constIt != myMap.end(); constIt++)
    std::cout << constIt->first << ", " << constIt->second << std::endl;

  prettyPrint(CODE_INSTRUCTIONS, "for (ft::map<char, int>::const_reverse_iterator constIt = myMap.rbegin(); constIt != myMap.rend(); constIt++)");
  for (ft::map<char, int>::const_reverse_iterator constIt = myMap.rbegin(); constIt != myMap.rend(); constIt++)
    std::cout << constIt->first << ", " << constIt->second << std::endl;

  ft::map<char, int>::iterator it;
  ft::map<char, int>::const_iterator constIt;
  ft::map<char, int>::reverse_iterator reverseIt;
  ft::map<char, int>::const_reverse_iterator constReverseIt;
  it = myMap.end();
	constIt = myMap.end();
	reverseIt = myMap.rbegin();
	constReverseIt = myMap.rbegin();

  prettyPrint(CODE_INSTRUCTIONS, "iterator == const_iterator");
  std::cout << (it == constIt) << std::endl;
  prettyPrint(CODE_INSTRUCTIONS, "iterator == iterator");
  std::cout << (it == it) << std::endl;
  prettyPrint(CODE_INSTRUCTIONS, "const_reverse_iterator == const_reverse_iterator");
  std::cout << (constIt == constIt) << std::endl;
  prettyPrint(CODE_INSTRUCTIONS, "reverse_iterator == const_reverse_iterator");
  std::cout << (reverseIt == constReverseIt) << std::endl;

  prettyPrint(CODE_INSTRUCTIONS, "iterator != const_iterator");
  std::cout << (it != constIt) << std::endl;
  prettyPrint(CODE_INSTRUCTIONS, "iterator != iterator");
  std::cout << (it != it) << std::endl;
  prettyPrint(CODE_INSTRUCTIONS, "const_reverse_iterator != const_reverse_iterator");
  std::cout << (constIt != constIt) << std::endl;
  prettyPrint(CODE_INSTRUCTIONS, "reverse_iterator != const_reverse_iterator");
  std::cout << (reverseIt != constReverseIt) << std::endl;

}
