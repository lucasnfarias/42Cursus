/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:20:48 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/14 16:38:03 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void  tests_empty()
{
  prettyPrint(SUBTITLE, "Test EMPTY function");

  prettyPrint(CODE_INSTRUCTIONS, "map<float> floats;");
  ft::map<float, float> floats;

  prettyPrint(CODE_INSTRUCTIONS, "floats.empty();");
  prettyPrint(RESULT, floats.empty());

  prettyPrint(CODE_INSTRUCTIONS, "floats.insert(ft::make_pair(21.2f, 42.7f));");
  floats.insert(ft::make_pair(21.2f, 42.7f));
  printMap(floats, true);

  prettyPrint(CODE_INSTRUCTIONS, "floats.empty();");
  prettyPrint(RESULT, floats.empty());

  prettyPrint(CODE_INSTRUCTIONS, "floats.erase(21.2);");
  floats.erase(21.2);

  prettyPrint(CODE_INSTRUCTIONS, "floats.empty();");
  prettyPrint(RESULT, floats.empty());

  prettyPrint(CODE_INSTRUCTIONS, "map<char> chars(3, 'L');");
  ft::map<char, char> chars;
  chars['a'] = 'c';
  printMap(chars, true);

  prettyPrint(CODE_INSTRUCTIONS, "chars.empty();");
  prettyPrint(RESULT, chars.empty());

}
