/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 19:01:21 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/10 18:02:44 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include "../containers/vector.hpp"

#include <stdlib.h>

enum LibType { FT = 0, STD = 1 };
enum ContainerType { VECTOR = 0, MAP = 1 };

void printResultHeader(LibType lib, ContainerType container_type)
{
  std::cout << std::endl;
  if (lib == FT)
    std::cout << "FT ";
  else if (lib == STD)
    std::cout << "STD ";

  if (container_type == VECTOR)
    std::cout << "Vector ";
  else if (container_type == MAP)
    std::cout << "Map ";

  std::cout
    << "result:"
    << std::endl;
}

void intVectorTest()
{
  ft::vector<int> ftVectorIntTest;
  std::vector<int> stdVectorIntTest;

  ftVectorIntTest.insert(ftVectorIntTest.begin(), 5, 42);
  stdVectorIntTest.insert(stdVectorIntTest.begin(), 5, 42);
  ftVectorIntTest.push_back(1);
  ftVectorIntTest.push_back(21);
  ftVectorIntTest.push_back(-12);
  stdVectorIntTest.push_back(1);
  stdVectorIntTest.push_back(21);
  stdVectorIntTest.push_back(-12);

  printResultHeader(FT, VECTOR);
  for (unsigned i=0; i< ftVectorIntTest.size(); ++i)
    std::cout << ftVectorIntTest[i] << " ";

  printResultHeader(STD, VECTOR);
  for (unsigned i=0; i< stdVectorIntTest.size(); ++i)
    std::cout << stdVectorIntTest[i] << " ";

  ftVectorIntTest.erase(ftVectorIntTest.begin() + 1);
  stdVectorIntTest.erase(stdVectorIntTest.begin() + 1);

  printResultHeader(FT, VECTOR);
  for (unsigned i=0; i< ftVectorIntTest.size(); ++i)
    std::cout << ftVectorIntTest[i] << " ";

  printResultHeader(STD, VECTOR);
  for (unsigned i=0; i< stdVectorIntTest.size(); ++i)
    std::cout << stdVectorIntTest[i] << " ";
  std::cout << std::endl;
}

void myVectorTests() {
  intVectorTest();
}

