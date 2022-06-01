/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:07:09 by lniehues          #+#    #+#             */
/*   Updated: 2022/06/01 20:50:10 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

static void intTest()
{
  std::cout << "###############" << std::endl;
  std::cout << "# 1. INT TEST #" << std::endl;
  std::cout << "###############" << std::endl;
  Array<int> intArray(5);
  Array<const int> intArray2(3);

  std::cout << "\n@ 1.a. test access index out of range:\n" << std::endl;

  std::cout << "intArray.size() = " << intArray.size() << std::endl;
  std::cout << "intArray2.size() = " << intArray2.size() << std::endl;

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
  printArray(intArray);

  enterToContinue();

  std::cout << "\n@ 1.d. empty constructor - e.g. Array emptyArray;\n" << std::endl;

  Array<int> emptyArray;
  printArray(emptyArray,"emptyArray");

  enterToContinue();

  std::cout << "\n@ 1.e. copy constructor - e.g. Array<int> copyArray(intArray);\n" << std::endl;

  Array<int> copyArray(intArray);
  printArray(copyArray, "copyArray");

  enterToContinue();
{
  std::cout << "\n@ 1.f. assign big array to a smaller array \n" << std::endl;

  Array<int> bigArray(10);
  Array<int> smallArray(5);
  for (unsigned int i = 0; i < bigArray.size(); i++)
  {
      bigArray[i] = 21;
      std::cout << "bigArray[" << i << "] = " << bigArray[i] << std::endl;
  }
  std::cout << std::endl;
  printArray(smallArray, "smallArray");
  smallArray = bigArray;
  printArray(smallArray, "smallArray");

  enterToContinue();
}

{
  std::cout << "\n@ 1.g. assign small array to a bigger array \n" << std::endl;

  Array<int> bigArray(10);
  Array<int> smallArray(5);
  for (unsigned int i = 0; i < smallArray.size(); i++)
  {
      smallArray[i] = 84;
      std::cout << "smallArray[" << i << "] = " << smallArray[i] << std::endl;
  }
  std::cout << std::endl;
  printArray(bigArray, "bigArray");
  bigArray = smallArray;
  printArray(bigArray, "bigArray");

  enterToContinue();
}

  std::cout << "\n@ 1.h. const int Array can't modify values - CHECK CODE \n" << std::endl;

  Array<const int> constArray(10);
  // constArray[0] = 2;
  printArray(constArray, "constArray");
  enterToContinue();
}

static void charTest()
{
  std::cout << "################" << std::endl;
  std::cout << "# 2. CHAR TEST #" << std::endl;
  std::cout << "################" << std::endl;
  Array<char> charArray(5);

  std::cout << "\n@ 1.a. assign values to array's elements:\n" << std::endl;

  printArray(charArray);
  for (unsigned int i = 0; i < charArray.size(); i++)
  {
    try
    {
      charArray[i] = i + 33;
      std::cout << "charArray[" << i << "] = " << charArray[i] << std::endl;
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << std::endl;
    }
  }
  enterToContinue();

  std::cout << "\n@ 1.b. change specific array index - e.g. charArray[2] = 'C'\n" << std::endl;

  charArray[0] = 'L';
  charArray[1] = 'U';
  charArray[2] = 'C';
  charArray[3] = 65;
  charArray[4] = 'S';
  printArray(charArray);

  enterToContinue();

  std::cout << "\n@ 1.c. empty constructor - e.g. Array emptyArray;\n" << std::endl;

  Array<char> emptyArray;
  printArray(emptyArray,"emptyArray");

  enterToContinue();

  std::cout << "\n@ 1.d. copy constructor - e.g. Array<char> copyArray(charArray);\n" << std::endl;

  Array<char> copyArray(charArray);
  printArray(copyArray, "copyArray");

  enterToContinue();

  std::cout << "\n@ 1.f. const char Array can't modify values - CHECK CODE \n" << std::endl;

  Array<const char> constArray(10);
  // constArray[0] = 'c';
  printArray(constArray, "constArray");
  enterToContinue();
}

static void stringTest()
{
  std::cout << "##################" << std::endl;
  std::cout << "# 3. STRING TEST #" << std::endl;
  std::cout << "##################" << std::endl;
  Array<std::string> strArray(5);

  std::cout << "\n@ 1.a. assign values to array's elements:\n" << std::endl;

  printArray(strArray);
  for (unsigned int i = 0; i < strArray.size(); i++)
  {
    try
    {
      strArray[i] = "Mads Mikelsen";
      std::cout << "strArray[" << i << "] = " << strArray[i] << std::endl;
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << std::endl;
    }
  }
  enterToContinue();

  std::cout << "\n@ 1.b. change specific array index - e.g. strArray[2] = 'Panic'\n" << std::endl;

  strArray[0] = "Do";
  strArray[1] = "Not";
  strArray[2] = "Panic";
  strArray[3] = "!";
  strArray[4] = "42";
  printArray(strArray);

  enterToContinue();

  std::cout << "\n@ 1.c. empty constructor - e.g. Array emptyArray;\n" << std::endl;

  Array<std::string> emptyArray;
  printArray(emptyArray,"emptyArray");

  enterToContinue();

  std::cout << "\n@ 1.d. copy constructor - e.g. Array<std::string> copyArray(strArray);\n" << std::endl;

  Array<std::string> copyArray(strArray);
  printArray(copyArray, "copyArray");

  enterToContinue();

  std::cout << "\n@ 1.e. const std::string Array can't modify values - CHECK CODE \n" << std::endl;

  Array<const std::string> constArray(10);
  // constArray[0] = "42";
  printArray(constArray, "constArray");
  enterToContinue();
}

static void classTest()
{
  std::cout << "##################" << std::endl;
  std::cout << "# 4. CLASS TEST #" << std::endl;
  std::cout << "##################" << std::endl;
  Array<Example> classArray(3);

  std::cout << "\n@ 1.a. assign values to array's elements:\n" << std::endl;

  printArray(classArray);
  for (unsigned int i = 0; i < classArray.size(); i++)
  {
    try
    {
      classArray[i] = Example("Legolas");
      std::cout << "classArray[" << i << "] = " << classArray[i] << std::endl;
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << std::endl;
    }
  }
  enterToContinue();

  std::cout << "\n@ 1.b. change specific array index - e.g. classArray[2] = Example('Hermione');\n" << std::endl;

  classArray[2] = Example("Hermione");
  printArray(classArray);

  enterToContinue();

  std::cout << "\n@ 1.c. copy constructor - e.g. Array<Example> copyArray(classArray);\n" << std::endl;

  Array<Example> copyArray(classArray);
  printArray(copyArray, "copyArray");

  enterToContinue();
}

int main()
{
  intTest();
  charTest();
  stringTest();
  classTest();
}
