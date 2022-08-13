/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:20:48 by lniehues          #+#    #+#             */
/*   Updated: 2022/08/12 21:07:02 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void  tests_erase()
{
  prettyPrint(SUBTITLE, "Test ERASE function");

  prettyPrint(CODE_INSTRUCTIONS, "vector<int> ints;");
  ft::vector<int> ints;

  prettyPrint(CODE_INSTRUCTIONS, "ints.push_back(int); 10 times");
  ints.push_back(12);
  ints.push_back(-12);
  ints.push_back(42);
  ints.push_back(1);
  ints.push_back(1000);
  ints.push_back(21);
  ints.push_back(-396);
  ints.push_back(666);
  ints.push_back(777);
  ints.push_back(123);
  printVector(ints);

  prettyPrint(CODE_INSTRUCTIONS, "ints.erase(ints.begin() + 5);");
  ints.erase(ints.begin() + 5);
  printVector(ints);

  prettyPrint(CODE_INSTRUCTIONS, "ints.erase(ints.begin());");
  ints.erase(ints.begin());
  printVector(ints);

  prettyPrint(CODE_INSTRUCTIONS, "ints.erase(ints.begin(), ints.end() - 5);");
  ints.erase(ints.begin(), ints.end() - 5);
  printVector(ints);

}
