/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 21:24:23 by lniehues          #+#    #+#             */
/*   Updated: 2022/06/12 20:49:58 by lniehues         ###   ########.fr       */
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
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
  enterToContinue();
}

static void simpleTest()
{
  Span sp(5);

  std::cout << "\n@1. Simple Test\n" << std::endl;

  std::cout << sp << std::endl;
  std::cout << "Size: " << sp.getSize() << std::endl;

  for (unsigned int i = 0; i < sp.getSize(); i++)
    sp.addNumber(i);

  try
  {
    sp.addNumber(-42);
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }

  std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
  std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
  enterToContinue();
}

static void bigArrayTest()
{
  Span sp(10000);

  std::cout << "\n@2. Big Array Test\n" << std::endl;

  std::cout << sp << std::endl;
  std::cout << "Size: " << sp.getSize() << std::endl;

  for (unsigned int i = 0; i < sp.getSize() - 1; i++)
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
  int arr[6] = { 23, -42, 84, 21, 1, 6 };
  int arr2[3] = { 1, 2, 3 };

  std::cout << "\n@3. Iterator Test\n" << std::endl;

  std::cout << sp << std::endl;
  std::cout << "Size: " << sp.getSize() << std::endl;

  for (unsigned int i = 0; i < 5; i++)
    sp.addNumber(i);

  sp.addNumber(arr, arr + 3);
  try
  {
    sp.addNumber(arr2 + 1, arr2 + 2);
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

#include <vector>

int main()
{
  subjectSuggestedTest();

  std::cout << "# MY TESTS #\n" << std::endl;
  simpleTest();
  bigArrayTest();
  iteratorTest();
}
