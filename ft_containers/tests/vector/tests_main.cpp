/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 19:07:09 by lniehues          #+#    #+#             */
/*   Updated: 2022/08/11 21:40:31 by lniehues         ###   ########.fr       */
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

  // tests_clear();
  tests_empty();

  end = clock();
	elapsed_time = end - start;
	std::cout << std::endl << VERSION << std::endl;
	std::cout << "Test duration:" << static_cast<float>(elapsed_time) / CLOCKS_PER_SEC << std::endl;
}
