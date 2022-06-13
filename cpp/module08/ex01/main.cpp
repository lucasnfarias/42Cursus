/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 21:24:23 by lniehues          #+#    #+#             */
/*   Updated: 2022/06/13 20:16:18 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

static void enterToContinue()
{
  std::cout << "\nPress enter to continue...\n";
  std::cin.ignore();
}

static void subjectSuggestedTest()
{
  std::cout << "# SUBJECT's SUGGESTED MAIN TEST #\n" << std::endl;
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);

  for (unsigned int i = 0; i < sp.getSize(); i++)
    std::cout << "span[" << i << "] = " << sp[i] << std::endl;

  std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
  std::cout << "Longest span: " << sp.longestSpan() << std::endl;
  enterToContinue();
}

static void simpleTest()
{
  Span sp(5);

  std::cout << "\n@1. Simple Test\n" << std::endl;

  std::cout << sp << std::endl;

  for (unsigned int i = 0; i < sp.getCapacity(); i++)
    sp.addNumber(i);

  try
  {
    std::cout << "Trying to add -42 to a full array..." << std::endl;
    sp.addNumber(-42);
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }

  for (unsigned int i = 0; i < sp.getSize(); i++)
    std::cout << "span[" << i << "] = " << sp[i] << std::endl;

  std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
  std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
  enterToContinue();
}

static void bigArrayTest()
{
  Span sp(10000);

  std::cout << "\n@2. Big Array Test\n" << std::endl;

  std::cout << sp << std::endl;

  std::cout << "Adding 0 to 9999 in array..." << std::endl;

  for (unsigned int i = 0; i < sp.getCapacity() - 1; i++)
    sp.addNumber(i);

  std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
  std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

  std::cout << "Adding -42 to array..." << std::endl;
  sp.addNumber(-42);

  std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
  std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

  enterToContinue();
}

static void iteratorTest()
{
  Span sp(10);
  std::vector<int> arr;
  arr.push_back(23);
  arr.push_back(-42);
  arr.push_back(84);
  arr.push_back(21);
  arr.push_back(1);
  arr.push_back(6);

  std::vector<int> arr2;
  arr2.push_back(1);
  arr2.push_back(2);
  arr2.push_back(3);

  std::cout << "\n@3. Iterator Test\n" << std::endl;

  std::cout << sp << std::endl;

  for (unsigned int i = 0; i < 5; i++)
    sp.addNumber(i);

  sp.addNumber(arr.begin(), arr.begin() + 4);
  try
  {
    sp.addNumber(arr2.begin() + 1, arr2.end());
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }

  for (unsigned int i = 0; i < sp.getSize(); i++)
    std::cout << "span[" << i << "] = " << sp[i] << std::endl;

  std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
  std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

  enterToContinue();

  std::cout << "\n@4. Copy Test\n" << std::endl;

  Span sp2(sp);

  for (unsigned int i = 0; i < sp2.getSize(); i++)
    std::cout << "span2[" << i << "] = " << sp2[i] << std::endl;

  std::cout << "Shortest Span2: " << sp2.shortestSpan() << std::endl;
  std::cout << "Longest Span2: " << sp2.longestSpan() << std::endl;

  enterToContinue();
}

int main()
{
  subjectSuggestedTest();

  std::cout << "# MY TESTS #\n" << std::endl;
  simpleTest();
  bigArrayTest();
  iteratorTest();
}
