/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:07:09 by lniehues          #+#    #+#             */
/*   Updated: 2022/05/31 22:31:08 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

static void enterToContinue()
{
  std::cout << "\nPress enter to continue...\n";
  std::cin.ignore();
}

static void printIntArray(Array<int> &array)
{
  for (unsigned int i = 0; i < array.size(); i++)
  {
    try
    {
      std::cout << "intArray[" << i << "] = " << array[i] << std::endl;
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << std::endl;
    }
  }
}

int main()
{
  std::cout << "# 1. TEST INT" << std::endl;
  Array<int> intArray(5);
  Array<const int> intArray2(3);

  std::cout << "\n@ 1.a. test access index out of range:\n" << std::endl;

  for (unsigned int i = 0; i < intArray.size(); i++)
  {
    try
    {
      std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
      std::cout << "intArray2[" << i << "] = " << intArray2[i] << std::endl;
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << std::endl;
    }
  }
  enterToContinue();

  std::cout << "\n@ 1.b. assign values to array's elements:\n" << std::endl;

  for (unsigned int i = 0; i < intArray.size(); i++)
  {
    try
    {
      intArray[i] = i;
      std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << std::endl;
    }
  }
  enterToContinue();

  std::cout << "\n@ 1.c. change specific array index - e.g. intArray[2] = 42\n" << std::endl;

  intArray[2] = 42;
  printIntArray(intArray);

  enterToContinue();

  // test int empty constructor
  // test int copy and assign
  // test too small to copy

  // test char
  // test string
}
