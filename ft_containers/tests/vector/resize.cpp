/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:20:48 by lniehues          #+#    #+#             */
/*   Updated: 2022/08/13 14:16:16 by lniehues         ###   ########.fr       */
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

  /*
  If you compare this floats.resize(1); part with the std it will reduce the capacity to 1, but the docs say it should not do that.

  https://en.cppreference.com/w/cpp/container/vector/reserve
  https://gcc.gnu.org/onlinedocs/gcc-4.6.3/libstdc++/api/a01115_source.html

  Increase the capacity of the vector (the total number of elements that the vector can hold without requiring reallocation)
  to a value that's greater or equal to new_cap. If new_cap is greater than the current capacity(), new storage is allocated,
  otherwise the function does nothing. reserve() does not change the size of the vector.
  */

  prettyPrint(CODE_INSTRUCTIONS, "floats.resize(20);");
  floats.resize(20);
  printVector(floats, true, true);
}
