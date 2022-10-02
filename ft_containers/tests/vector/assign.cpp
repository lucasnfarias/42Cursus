/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:20:48 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/27 21:11:51 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void  tests_assign()
{
  prettyPrint(SUBTITLE, "Test ASSIGN function");

  prettyPrint(CODE_INSTRUCTIONS, "ft::vector<std::string> strings;");
  ft::vector<std::string> strings;

  prettyPrint(CODE_INSTRUCTIONS, "strings.assign(42, 'Marvin');");
  strings.assign(42, "Marvin");

  printVector(strings, true, true);

  prettyPrint(CODE_INSTRUCTIONS, "strings.assign(strings.begin() + 12, strings.end() - 3);");
  strings.assign(strings.begin() + 12, strings.end() - 3);

  printVector(strings, true, true);

  try {
    prettyPrint(CODE_INSTRUCTIONS, "strings.assign(strings.max_size() + 1, 'Marvin');");
    strings.assign(strings.max_size() + 1, "Marvin");
    printVector(strings);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

}
