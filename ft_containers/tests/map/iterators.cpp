/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:20:48 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/23 22:32:07 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void  tests_iterators()
{
  prettyPrint(SUBTITLE, "Test ITERATORS function");

  prettyPrint(CODE_INSTRUCTIONS, "ft::map<std::string,int> cosmos;");
  ft::map<std::string, int> cosmos;

  prettyPrint(CODE_INSTRUCTIONS, "cosmos['Andromeda'] = 42;");
  cosmos["Andromeda"] = 42;
  prettyPrint(CODE_INSTRUCTIONS, "cosmos['Mercurio'] = 21;");
  cosmos["Mercurio"] = 21;
  prettyPrint(CODE_INSTRUCTIONS, "cosmos['Sol'] = 8;");
  cosmos["Sol"] = 8;
  prettyPrint(CODE_INSTRUCTIONS, "cosmos['Prometeu'] = 42;");
  cosmos["Prometeu"] = 42;
  prettyPrint(CODE_INSTRUCTIONS, "cosmos['Tita'] = -2;");
  cosmos["Tita"] = -2;

  prettyPrint(CODE_INSTRUCTIONS, "for (ft::map<std::string, int>::iterator it = cosmos.begin(); it != cosmos.end(); it++)");
  for (ft::map<std::string, int>::iterator it = cosmos.begin(); it != cosmos.end(); it++)
    std::cout << it->first << ", " << it->second << std::endl;

  prettyPrint(CODE_INSTRUCTIONS, "for (ft::map<std::string, int>::reverse_iterator it = cosmos.rbegin(); it != cosmos.rend(); it++)");
  for (ft::map<std::string, int>::reverse_iterator it = cosmos.rbegin(); it != cosmos.rend(); it++)
    std::cout << it->first << ", " << it->second << std::endl;

  prettyPrint(CODE_INSTRUCTIONS, "for (ft::map<std::string, int>::const_iterator constIt = cosmos.begin(); constIt != cosmos.end(); constIt++)");
  for (ft::map<std::string, int>::const_iterator constIt = cosmos.begin(); constIt != cosmos.end(); constIt++)
    std::cout << constIt->first << ", " << constIt->second << std::endl;

  prettyPrint(CODE_INSTRUCTIONS, "for (ft::map<std::string, int>::const_reverse_iterator constIt = cosmos.rbegin(); constIt != cosmos.rend(); constIt++)");
  for (ft::map<std::string, int>::const_reverse_iterator constIt = cosmos.rbegin(); constIt != cosmos.rend(); constIt++)
    std::cout << constIt->first << ", " << constIt->second << std::endl;

  ft::map<std::string, int>::iterator it;
  ft::map<std::string, int>::const_iterator constIt;
  ft::map<std::string, int>::reverse_iterator reverseIt;
  ft::map<std::string, int>::const_reverse_iterator constReverseIt;
  it = cosmos.end();
	constIt = cosmos.end();
	reverseIt = cosmos.rbegin();
	constReverseIt = cosmos.rbegin();

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
