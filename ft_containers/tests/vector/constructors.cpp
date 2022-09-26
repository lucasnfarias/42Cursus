/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:20:48 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/26 19:03:53 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void  tests_constructors()
{
  prettyPrint(SUBTITLE, "Test CONSTRUCTORS");

  prettyPrint(DESCRIPTION, "test DEFAULT constructor");

  prettyPrint(CODE_INSTRUCTIONS, "vector<char> chars;");
  ft::vector<char> chars;

  prettyPrint(CODE_INSTRUCTIONS, "chars.push_back(char); 6 times");

  chars.push_back('D');
  chars.push_back('P');
  chars.push_back('4');
  chars.push_back('i');
  chars.push_back('w');
  chars.push_back('y');

  printVector(chars, true);

  prettyPrint(DESCRIPTION, "test FILL constructor");
  prettyPrint(CODE_INSTRUCTIONS, "vector<std::string> strings(500, 'Don't Panic!');");
  ft::vector<std::string> strings(500, "Don't Panic!");

  printVector(strings, true);

  prettyPrint(DESCRIPTION, "test RANGE constructor");
  prettyPrint(CODE_INSTRUCTIONS, "vector<char> charsCopy(chars.begin() + 2, chars.end() - 1);");
  ft::vector<char>charsCopy(chars.begin() + 2, chars.end() - 1);

  printVector(charsCopy, true);

  prettyPrint(DESCRIPTION, "test COPY constructor");
  prettyPrint(CODE_INSTRUCTIONS, "vector<char> charsRangeCopy(charsCopy);");
  ft::vector<char>charsRangeCopy(charsCopy);

  printVector(charsRangeCopy, true);
}
