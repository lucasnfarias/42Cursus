/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at_front_back.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:20:48 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/27 19:11:54 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void  tests_at_front_back()
{
  prettyPrint(SUBTITLE, "Test ELEMENT ACCESS functions");

  prettyPrint(DESCRIPTION, "test AT function");

  prettyPrint(CODE_INSTRUCTIONS, "vector<int> ints;");
  ft::vector<int> ints;

  prettyPrint(CODE_INSTRUCTIONS, "ints.push_back(char); 6 times");

  ints.push_back(32222);
  ints.push_back(-1111111);
  ints.push_back(765);
  ints.push_back(32);
  ints.push_back(-21);

  printVector(ints, true);

  prettyPrint(CODE_INSTRUCTIONS, "ints.at(2)");
  std::cout << "ints[2] = " << ints.at(2) << std::endl;

  try {
    prettyPrint(CODE_INSTRUCTIONS, "int &value = ints.at(9);");
    int &value = ints.at(9);
    std::cout << "ints[9] = " << value << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  prettyPrint(DESCRIPTION, "test FRONT function");

  prettyPrint(CODE_INSTRUCTIONS, "ints.front()");
  std::cout << "ints front element = " << ints.front() << std::endl;

  prettyPrint(DESCRIPTION, "test BACK function");

  prettyPrint(CODE_INSTRUCTIONS, "ints.back()");
  std::cout << "ints back element = " << ints.back() << std::endl;

  prettyPrint(CODE_INSTRUCTIONS, "vector<float> floats(120, 100.42f);");
  ft::vector<float> floats(120, 100.42f);

  printVector(floats, true);

  prettyPrint(CODE_INSTRUCTIONS, "ft::vector<float>::const_reference constRef = floats.back();");
  ft::vector<float>::const_reference constRef = floats.back();
  std::cout << "floats back element = " << constRef << std::endl;

  printVector(floats, true);
}
