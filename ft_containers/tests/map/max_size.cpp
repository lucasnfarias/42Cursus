/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_size.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:39:49 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/24 18:39:50 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void  tests_max_size()
{
  prettyPrint(SUBTITLE, "Test MAX_SIZE function");

  prettyPrint(CODE_INSTRUCTIONS, "map<int,int> ints;");

  int i;
  ft::map<int,int> ints;

  if (ints.max_size() > 1000)
  {
    for (i = 0; i < 1000; i++) ints[i] = 0;

    std::cout << "The map contains 1000 elements.\n";
  }
  else std::cout << "The map could not hold 1000 elements.\n";

}
