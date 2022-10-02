/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reserve.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:20:48 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/27 19:25:52 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void  tests_reserve()
{
  prettyPrint(SUBTITLE, "Test RESERVE function");

  prettyPrint(CODE_INSTRUCTIONS, "vector<int> ints;");
  ft::vector<int> ints;

  prettyPrint(CODE_INSTRUCTIONS, "ints.push_back(int); 3 times");
  ints.push_back(123);
  ints.push_back(84);
  ints.push_back(-1001);
  printVector(ints, true, true);

  prettyPrint(CODE_INSTRUCTIONS, "ints.reserve(5);");
  ints.reserve(5);
  printVector(ints, true, true);

  prettyPrint(CODE_INSTRUCTIONS, "ints.reserve(30);");
  ints.reserve(30);
  printVector(ints, true, true);

  try {
    prettyPrint(CODE_INSTRUCTIONS, "ints.reserve(ints.max_size());");
    ints.reserve(ints.max_size() + 1);
    printVector(ints);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

}
