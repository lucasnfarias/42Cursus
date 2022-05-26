/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifyRealType.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:28:07 by lniehues          #+#    #+#             */
/*   Updated: 2022/05/25 21:52:53 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identifyRealType.hpp"
#include <iostream>
#include <cstdlib>

Base *generate(void)
{
  Base *classPtr;
  int randomNum;

  std::cout << "# CLASS GENERATOR\n"
            << std::endl;
  std::srand((unsigned int)time(NULL));
  randomNum = rand() % 3;

  switch (randomNum)
  {
  case 1:
    classPtr = new A();
    std::cout << "Class A generated" << std::endl;
    break;
  case 2:
    classPtr = new B();
    std::cout << "Class B generated" << std::endl;
    break;
  default:
    classPtr = new C();
    std::cout << "Class C generated" << std::endl;
    break;
  }
  std::cout << "--------------------\n" << std::endl;
  return classPtr;
}

void identify(Base *p)
{
  std::cout << "# Identify Real Type By POINTER\n"
            << std::endl;
  std::cout << "Real Type: ";
  if (dynamic_cast<A *>(p))
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C *>(p))
    std::cout << "C" << std::endl;
  std::cout << "-------------------\n" << std::endl;
}

void identify(Base &p)
{
  std::cout << "# Identify Real Type By REFERENCE\n"
            << std::endl;

  std::cout << "Real Type: ";
  try
  {
    dynamic_cast<A &>(p);

    std::cout << "A" << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << " - Not A" << std::endl;
  }
  std::cout << "Real Type: ";
  try
  {
    dynamic_cast<B &>(p);
    std::cout << "B" << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << " - Not B" << std::endl;
  }
  std::cout << "Real Type: ";
  try
  {
    dynamic_cast<C &>(p);
    std::cout << "C" << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << " - Not C" << std::endl;
  }
  std::cout << "-------------------\n" << std::endl;
}
