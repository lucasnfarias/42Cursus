/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 21:24:23 by lniehues          #+#    #+#             */
/*   Updated: 2022/06/10 21:18:20 by lniehues         ###   ########.fr       */
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

  // std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
  std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
  enterToContinue();
}

static void bigArrayTest()
{
  Span sp(10000);

  std::cout << sp << std::endl;
  std::cout << "Size: " << sp.getSize() << std::endl;

  for (unsigned int i = 0; i < sp.getSize(); i++)
    sp.addNumber(i);

  // std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
  std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
  enterToContinue();
}

int main()
{
  subjectSuggestedTest();

  std::cout << "# MY TESTS #\n" << std::endl;
  simpleTest();
  bigArrayTest();
}
