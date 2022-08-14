/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:20:48 by lniehues          #+#    #+#             */
/*   Updated: 2022/08/14 20:26:34 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void  tests_resize()
{
  prettyPrint(SUBTITLE, "Test RESIZE function");

  prettyPrint(CODE_INSTRUCTIONS, "ft::vector<float> floats(5, 77.1);");
  ft::vector<float> floats(5, 77.1);
  printVector(floats, true, true);

  prettyPrint(CODE_INSTRUCTIONS, "floats.resize(5);");
  floats.resize(5);
  printVector(floats, true, true);

  prettyPrint(CODE_INSTRUCTIONS, "floats.resize(1);");
  floats.resize(1);
  printVector(floats, true, true);

  prettyPrint(CODE_INSTRUCTIONS, "floats.resize(20);");
  floats.resize(20);
  printVector(floats, true, true);
}
