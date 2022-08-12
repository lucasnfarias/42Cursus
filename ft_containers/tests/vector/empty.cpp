/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:20:48 by lniehues          #+#    #+#             */
/*   Updated: 2022/08/11 21:57:29 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void  tests_empty()
{
  prettyPrint(SUBTITLE, "Test EMPTY function");

  prettyPrint(CODE_INSTRUCTIONS, "vector<float> floats;");
  ft::vector<float> floats;

  prettyPrint(CODE_INSTRUCTIONS, "floats.empty();");
  prettyPrint(RESULT, floats.empty());

  prettyPrint(CODE_INSTRUCTIONS, "floats.push_back(42.7);");
  floats.push_back(42.7);
  printVector(floats, true);

  prettyPrint(CODE_INSTRUCTIONS, "floats.empty();");
  prettyPrint(RESULT, floats.empty());

  prettyPrint(CODE_INSTRUCTIONS, "floats.pop_back();");
  floats.pop_back();

  prettyPrint(CODE_INSTRUCTIONS, "floats.empty();");
  prettyPrint(RESULT, floats.empty());

  prettyPrint(CODE_INSTRUCTIONS, "vector<char> chars(3, 'L');");
  ft::vector<char> chars(3, 'L');
  printVector(chars, true);

  prettyPrint(CODE_INSTRUCTIONS, "chars.empty();");
  prettyPrint(RESULT, floats.empty());

}
