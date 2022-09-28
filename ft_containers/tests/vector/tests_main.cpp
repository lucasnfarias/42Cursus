/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:07:09 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/28 19:26:10 by lniehues         ###   ########.fr       */
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

  prettyPrint(TITLE, "VECTOR container tests");

  tests_constructors();
  tests_operators();
  tests_iterators();
  tests_clear();
  tests_empty();
  tests_erase();
  tests_resize();
  tests_reserve();
  tests_at_front_back();
  tests_assign();
  tests_push_back();
  tests_pop_back();
  tests_swap();
  tests_get_allocator();
  tests_insert();

  end = clock();
	elapsed_time = end - start;
	std::cout << std::endl << VERSION << std::endl;
	std::cout << "Test duration:" << static_cast<float>(elapsed_time) / CLOCKS_PER_SEC << std::endl;
}
