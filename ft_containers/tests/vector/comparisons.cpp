/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparisons.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:20:48 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/28 20:44:10 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

template <typename T1>
void vectorCompare(ft::vector<T1> &vector1, ft::vector<T1> &vector2)
{
  if (vector1 == vector2)
    std::cout << "vector1 is EQUAL to vector2" << std::endl;
  if (vector1 != vector2)
    std::cout << "vector1 is NOT EQUAL to vector2" << std::endl;
  if (vector1 < vector2)
    std::cout << "vector1 is LESS THAN vector2" << std::endl;
  if (vector1 > vector2)
    std::cout << "vector1 is GREATER THAN vector2" << std::endl;
  if (vector1 <= vector2)
    std::cout << "vector1 is LESS THAN or EQUAL to vector2" << std::endl;
  if (vector1 >= vector2)
    std::cout << "vector1 is GREATER THAN or EQUAL to vector2" << std::endl;

  std::cout << std::endl;
}

void  tests_comparisons()
{
  prettyPrint(SUBTITLE, "Test COMPARISONS");

  prettyPrint(DESCRIPTION, "test <, >, >=, <= comparison");

  prettyPrint(CODE_INSTRUCTIONS, "vector<int> vector1(400, 42);");
  prettyPrint(CODE_INSTRUCTIONS, "vector<int> vector2(400, 42);");
  ft::vector<int> vector1(400, 42);
  ft::vector<int> vector2(400, 42);

  printVector(vector1, true);
  printVector(vector2, true);
  vectorCompare(vector1, vector2);
  vectorCompare(vector2, vector1);

  vector1[2] = -42;

  printVector(vector1, true);
  printVector(vector2, true);
  vectorCompare(vector1, vector2);
  vectorCompare(vector2, vector1);

  prettyPrint(DESCRIPTION, "test EQUAL comparison");

  prettyPrint(CODE_INSTRUCTIONS, "vector<char> vector3;");
  prettyPrint(CODE_INSTRUCTIONS, "vector<char> vector4;");
  ft::vector<char> vector3;
  ft::vector<char> vector4;

  prettyPrint(DESCRIPTION, "test equal comparison w/ vectors same size and elements");

  vector3.push_back('c');
  vector3.push_back('d');
  vector4.push_back('c');
  vector4.push_back('d');

  printVector(vector3, true);
  printVector(vector4, true);
  vectorCompare(vector3, vector4);

  prettyPrint(DESCRIPTION, "test equal comparison w/ vectors same size and different element values");

  vector3.push_back('F');
  vector4.push_back('f');

  printVector(vector3, true);
  printVector(vector4, true);
  vectorCompare(vector3, vector4);

  prettyPrint(DESCRIPTION, "test equal comparison w/ vectors different size and elements");

  vector3.pop_back();

  printVector(vector3, true);
  printVector(vector4, true);
  vectorCompare(vector3, vector4);
  vectorCompare(vector4, vector3);

}
