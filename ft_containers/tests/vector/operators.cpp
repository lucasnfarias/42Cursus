/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:20:48 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/26 21:13:14 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void  tests_operators()
{
  prettyPrint(SUBTITLE, "Test OPERATORS");

  prettyPrint(DESCRIPTION, "test ASSIGN operator");

  prettyPrint(CODE_INSTRUCTIONS, "vector<char> chars;");
  ft::vector<char> chars;

  prettyPrint(CODE_INSTRUCTIONS, "chars.push_back(char); 6 times");

  chars.push_back('A');
  chars.push_back('M');
  chars.push_back('3');
  chars.push_back('n');
  chars.push_back('N');

  printVector(chars, true);

  prettyPrint(CODE_INSTRUCTIONS, "vector<char> charsCopy = chars;");
  ft::vector<char>charsCopy = chars;

  printVector(charsCopy, true);

  prettyPrint(DESCRIPTION, "test ACCESS operator");

  prettyPrint(CODE_INSTRUCTIONS, "vector<float> floats(120, 100.42f);");
  ft::vector<float> floats(120, 100.42f);

  printVector(floats, true);

  prettyPrint(CODE_INSTRUCTIONS, "floats[2] = 12.2f;");
  prettyPrint(CODE_INSTRUCTIONS, "floats[80] = 42.132f;");
  prettyPrint(CODE_INSTRUCTIONS, "floats[99] = -3.9999f;");

  floats[2] = 12.2f;
  floats[80] = 42.132f;
  floats[99] = -3.9999f;

  printVector(floats, true);
}
