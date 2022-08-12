/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:20:48 by lniehues          #+#    #+#             */
/*   Updated: 2022/08/11 21:31:58 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void  tests_clear()
{
  prettyPrint(SUBTITLE, "Test CLEAR function");

  ft::vector<std::string> strings;

  prettyPrint(CODE_INSTRUCTIONS, "vector<std::string> strings");
  prettyPrint(CODE_INSTRUCTIONS, "strings.push_back(std::string) 7 times");

  strings.push_back("Don't");
  strings.push_back("Panic");
  strings.push_back("42");
  strings.push_back("is");
  strings.push_back("with");
  strings.push_back("you");
  strings.push_back("<3");

  printVector(strings, true);

  prettyPrint(CODE_INSTRUCTIONS, "strings.clear()");

  strings.clear();

  printVector(strings, true);
}
