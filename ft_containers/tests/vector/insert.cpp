/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:20:48 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/28 20:33:00 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void  tests_insert()
{
  prettyPrint(SUBTITLE, "Test INSERT function");

  prettyPrint(CODE_INSTRUCTIONS, "ft::vector<int> ints(5000, 42);");
  ft::vector<int> ints(1000, 42);

  prettyPrint(CODE_INSTRUCTIONS, "ints.insert(ints.begin(), -1);");
  prettyPrint(CODE_INSTRUCTIONS, "ints.insert(ints.begin() + 20, 10000);");
  prettyPrint(CODE_INSTRUCTIONS, "ints.insert(ints.end() - 500, 123);");

  ints.insert(ints.begin(), -1);
  ints.insert(ints.begin() + 20, 10000);
  ints.insert(ints.end() - 500, 123);

  printVector(ints, true);

  prettyPrint(CODE_INSTRUCTIONS, "ints.insert(ints.begin(), -1);");
  ints.insert(ints.begin() + 10, 50, -42);

  printVector(ints, true);

  prettyPrint(CODE_INSTRUCTIONS, "ft::vector<int> ints2(100, 666);");
  ft::vector<int> ints2(100, 666);

  prettyPrint(CODE_INSTRUCTIONS, "ints.insert(ints.begin() + 500, ints2.begin(), ints2.end());");
  ints.insert(ints.begin() + 500, ints2.begin(), ints2.end());

  printVector(ints, true);
  printVector(ints2, true);

  prettyPrint(CODE_INSTRUCTIONS, "ints.insert(ints.begin() + 500, ints2.begin(), ints2.end());");
  ints.insert(ints.begin() + 700, ints2.begin(), ints2.end() - 50);

  printVector(ints, true);

}
