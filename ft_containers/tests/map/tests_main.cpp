/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:39:26 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/24 21:10:11 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"
#include <time.h>

int main()
{
  clock_t start;
  clock_t end;
  clock_t elapsed_time;

  std::cout.setf(std::ios::boolalpha);

  start = clock();

  prettyPrint(TITLE, "MAP container tests");

  tests_empty();
  tests_size();
  tests_max_size();
  tests_element_access_operator();
  tests_constructors_and_operators();
  tests_iterators();
  tests_insert();
  tests_erase();
  tests_swap();
  tests_clear();
  tests_key_value_compare();
  tests_find();
  tests_count();
  tests_lower_and_upper_bound();

  end = clock();
  elapsed_time = end - start;
  std::cout << std::endl << VERSION << std::endl;
  std::cout << "Test duration:" << static_cast<float>(elapsed_time) / CLOCKS_PER_SEC << std::endl;
}
