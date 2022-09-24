/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:41:39 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/24 14:12:30 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void  tests_constructors()
{
  prettyPrint(SUBTITLE, "Test CONSTRUCTORS function");

  prettyPrint(DESCRIPTION, "test DEFAULT constructor");
  prettyPrint(CODE_INSTRUCTIONS, "map<float,float> floats;");
  ft::map<float, float> floats;

  prettyPrint(CODE_INSTRUCTIONS, "floats[21.2f] = 42.7f;");
  floats[21.2f] = 42.7f;
  prettyPrint(CODE_INSTRUCTIONS, "floats[1.2f] = 3.7f;");
  floats[1.2f] = 3.7f;

  prettyPrint(DESCRIPTION, "test COPY constructor");
  prettyPrint(CODE_INSTRUCTIONS, "map<float,float> floatsCopy(floats);");
  ft::map<float, float> floatsCopy(floats);

  prettyPrint(CODE_INSTRUCTIONS, "floatsCopy[2.0f] = 3.1f;");
  floatsCopy[2.0f] = 3.1f;

  prettyPrint(DESCRIPTION, "test ITERATORS constructor");
  prettyPrint(CODE_INSTRUCTIONS,
  "ft::map<float, float> *floatsIteratorsCopyPtr = new ft::map<float, float>(floatsCopy.begin(), floatsCopy.end());");
  ft::map<float, float> *floatsIteratorsCopyPtr = new ft::map<float, float>(floatsCopy.begin(), floatsCopy.end());

  prettyPrint(CODE_INSTRUCTIONS, "floatsIteratorsCopyPtr->insert(ft::make_pair(222.4f, 32.2f));");
  floatsIteratorsCopyPtr->insert(ft::make_pair(222.4f, 32.2f));

  ft::map<float, float> floatsCopySigned = floats;

  prettyPrint(CODE_INSTRUCTIONS, "floatsCopySigned.erase(21.2f);");
  floatsCopySigned.erase(21.2f);

  printMap(floats, true, "floats");
  printMap(floatsCopy, true, "floatsCopy");
  printMap(*floatsIteratorsCopyPtr, true, "floatsIteratorsCopyPtr");
  printMap(floatsCopySigned, true, "floatsCopySigned");

  delete floatsIteratorsCopyPtr;

}
