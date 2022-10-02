/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:20:48 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/27 21:15:50 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void  tests_push_back()
{
  prettyPrint(SUBTITLE, "Test PUSH_BACK function");

  ft::vector<std::string> strings;

  prettyPrint(CODE_INSTRUCTIONS, "vector<std::string> strings;");
  prettyPrint(CODE_INSTRUCTIONS, "strings.push_back(std::string); 7 times");

  strings.push_back("Don't");
  strings.push_back("Panic");
  strings.push_back("42");
  strings.push_back("is");
  strings.push_back("with");
  strings.push_back("you");
  strings.push_back("<3");

  printVector(strings, true);

  prettyPrint(CODE_INSTRUCTIONS, "strings.push_back(std::string); 10000 times");

  for (size_t i = 0; i < 10000; i++) strings.push_back("42!");

  printVector(strings, true);
}
