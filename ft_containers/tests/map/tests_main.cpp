/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:39:26 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/13 16:59:14 by lniehues         ###   ########.fr       */
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

  ft::map<int, int> test;

  test.insert(ft::make_pair(2, 23));

  ft::map<int, int>::iterator it = test.begin();

  std::cout << it->first << ", " << it->second << std::endl;

  end = clock();
	elapsed_time = end - start;
	std::cout << std::endl << VERSION << std::endl;
	std::cout << "Test duration:" << static_cast<float>(elapsed_time) / CLOCKS_PER_SEC << std::endl;
}
