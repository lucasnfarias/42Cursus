/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 20:40:03 by lniehues          #+#    #+#             */
/*   Updated: 2022/06/13 20:43:53 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int main()
{
  MutantStack<int> mutant;

  mutant.push(2);
  std::cout << mutant.top() << std::endl;
  mutant.push(42);
  std::cout << mutant.top() << std::endl;
  mutant.push(-122);
  std::cout << mutant.top() << std::endl;
  mutant.pop();
  std::cout << mutant.top() << std::endl;

}
