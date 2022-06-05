/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:48:04 by lniehues          #+#    #+#             */
/*   Updated: 2022/06/05 17:19:20 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
  std::vector<int> vect;

  vect.push_back(1);
  vect.push_back(5);
  vect.push_back(42);
  vect.push_back(-1);

  for (size_t i = 0; i < vect.size(); i++)
    std::cout << vect[i] << std::endl;

  std::vector<int>::iterator p = find(vect.begin(), vect.end(), 42);
  std::cout << *p << std::endl;
}
