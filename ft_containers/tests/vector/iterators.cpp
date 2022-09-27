/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:20:48 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/26 21:55:24 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void  tests_iterators()
{
  prettyPrint(SUBTITLE, "Test ITERATORS");

  prettyPrint(CODE_INSTRUCTIONS, "vector<double> doubles;");
  prettyPrint(CODE_INSTRUCTIONS, "vector<const double> constDouble;");
  ft::vector<double> doubles;
  const ft::vector<double> constDouble(120, 123456789.21311);

  prettyPrint(CODE_INSTRUCTIONS, "doubles.push_back(double); 10 times");

  doubles.push_back(23.12);
  doubles.push_back(42);
  doubles.push_back(21.11111);
  doubles.push_back(-1212121.2);
  doubles.push_back(2323232.112233);
  doubles.push_back(999.666);
  doubles.push_back(111.66);
  doubles.push_back(234.626);
  doubles.push_back(1.566666);
  doubles.push_back(-10000000.8);

  printVector(doubles, true);

  printVector(constDouble, true);

  prettyPrint(CODE_INSTRUCTIONS, "vector<float> floats;");
  ft::vector<double>::iterator it;
  ft::vector<double>::const_iterator constIt;
  ft::vector<double>::reverse_iterator reverseIt;
  ft::vector<double>::const_reverse_iterator constReverseIt;
  ft::vector<double>::reverse_iterator reverseItRend;

  it = doubles.end();
  constIt = constDouble.end();
  reverseIt = doubles.rbegin();
  constReverseIt = constDouble.rbegin();
  reverseItRend = doubles.rend();

  prettyPrint(CODE_INSTRUCTIONS, "std::cout << *(it - 3) << std::endl;");
  prettyPrint(CODE_INSTRUCTIONS, "std::cout << *(constIt - 2) << std::endl;");
  prettyPrint(CODE_INSTRUCTIONS, "std::cout << *(reverseIt + 5) << std::endl;");
  prettyPrint(CODE_INSTRUCTIONS, "std::cout << *(++constReverseIt) << std::endl;");

  std::cout << *(it - 3) << std::endl;
  std::cout << *(constIt - 2) << std::endl;
  std::cout << *(reverseIt + 5) << std::endl;
  std::cout << *(++constReverseIt) << std::endl;
  std::cout << *(--reverseItRend) << std::endl;

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

  prettyPrint(CODE_INSTRUCTIONS, "iterator < const_iterator");
  std::cout << (it < constIt) << std::endl;
  prettyPrint(CODE_INSTRUCTIONS, "iterator < iterator");
  std::cout << (it < it) << std::endl;
  prettyPrint(CODE_INSTRUCTIONS, "const_reverse_iterator < const_reverse_iterator");
  std::cout << (constIt < constIt) << std::endl;
  prettyPrint(CODE_INSTRUCTIONS, "reverse_iterator < const_reverse_iterator");
  std::cout << (reverseIt < constReverseIt) << std::endl;

  prettyPrint(CODE_INSTRUCTIONS, "iterator <= const_iterator");
  std::cout << (it <= constIt) << std::endl;
  prettyPrint(CODE_INSTRUCTIONS, "iterator <= iterator");
  std::cout << (it <= it) << std::endl;
  prettyPrint(CODE_INSTRUCTIONS, "const_reverse_iterator <= const_reverse_iterator");
  std::cout << (constIt <= constIt) << std::endl;
  prettyPrint(CODE_INSTRUCTIONS, "reverse_iterator <= const_reverse_iterator");
  std::cout << (reverseIt <= constReverseIt) << std::endl;

  prettyPrint(CODE_INSTRUCTIONS, "iterator > const_iterator");
  std::cout << (it > constIt) << std::endl;
  prettyPrint(CODE_INSTRUCTIONS, "iterator > iterator");
  std::cout << (it > it) << std::endl;
  prettyPrint(CODE_INSTRUCTIONS, "const_reverse_iterator > const_reverse_iterator");
  std::cout << (constIt > constIt) << std::endl;
  prettyPrint(CODE_INSTRUCTIONS, "reverse_iterator > const_reverse_iterator");
  std::cout << (reverseIt > constReverseIt) << std::endl;

  prettyPrint(CODE_INSTRUCTIONS, "iterator >= const_iterator");
  std::cout << (it >= constIt) << std::endl;
  prettyPrint(CODE_INSTRUCTIONS, "iterator >= iterator");
  std::cout << (it >= it) << std::endl;
  prettyPrint(CODE_INSTRUCTIONS, "const_reverse_iterator >= const_reverse_iterator");
  std::cout << (constIt >= constIt) << std::endl;
  prettyPrint(CODE_INSTRUCTIONS, "reverse_iterator >= const_reverse_iterator");
  std::cout << (reverseIt >= constReverseIt) << std::endl;
}
