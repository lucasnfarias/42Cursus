/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:39:57 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/25 20:05:01 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void  tests_clear()
{
  prettyPrint(SUBTITLE, "Test CLEAR function");

  prettyPrint(CODE_INSTRUCTIONS, "ft::map<int,int> ints;");

  ft::map<int,int> ints;

  prettyPrint(CODE_INSTRUCTIONS, "for (int i = 0; i < 1000; i++) ints[i] = i * 4;");

  for (int i = 0; i < 1000; i++) ints[i] = i * 4;

  printMap(ints, false, "ints", true);

  prettyPrint(CODE_INSTRUCTIONS, "ints.clear();");
  ints.clear();

  printMap(ints, false, "ints", true);

  prettyPrint(CODE_INSTRUCTIONS, "for (int i = 0; i < 200; i++) ints[i] = i * 3;");
  for (int i = 0; i < 200; i++) ints[i] = i * 3;

  printMap(ints, false, "ints", true);
}
