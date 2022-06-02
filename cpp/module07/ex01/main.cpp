/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 01:46:27 by coder             #+#    #+#             */
/*   Updated: 2022/06/02 15:44:45 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "Example.hpp"

int main()
{
  int intArray[4] = {1, 3, 5, 8};
  char charArray[5] = {'a', '-', 'y', 'B', '4'};
  std::string stringArray[3] = {"Hello", "Top", "okidoki"};
  Example classArray[3];

  std::cout << "Print original arrays:\n" << std::endl;

  std::cout << "\n# intArray:" << std::endl;
  iter(intArray, 4, myPrint);
  std::cout << "\n# charArray:" << std::endl;
  iter(charArray, 5, myPrint);
  std::cout << "\n# stringArray:" << std::endl;
  iter(stringArray, 3, myPrint);
  std::cout << "\n# classArray:" << std::endl;
  iter(classArray, 3, myPrint);

  enterToContinue();

  std::cout << "Transforming arrays...\n" << std::endl;

  std::cout << "1. intArray iter with triple()\n" << std::endl;
  iter(intArray, 4, triple);
  std::cout << "2. charArray iter with minusOne()\n" << std::endl;
  iter(charArray, 5, minusOne);
  std::cout << "3. stringArray iter with add42ToString()\n" << std::endl;
  iter(stringArray, 3, add42ToString);
  std::cout << "4. classArray iter with plusTwoToGrade()\n" << std::endl;
  iter(classArray, 3, plusTwoToGrade);

  enterToContinue();

  std::cout << "Print transformed arrays:\n" << std::endl;

  std::cout << "\n# intArray:" << std::endl;
  iter(intArray, 4, myPrint);
  std::cout << "\n# charArray:" << std::endl;
  iter(charArray, 5, myPrint);
  std::cout << "\n# stringArray:" << std::endl;
  iter(stringArray, 3, myPrint);
  std::cout << "\n# classArray:" << std::endl;
  iter(classArray, 3, myPrint);
}
