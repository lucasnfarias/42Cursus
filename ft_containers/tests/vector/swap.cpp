/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:20:48 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/27 21:29:38 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void  tests_swap()
{
  prettyPrint(SUBTITLE, "Test SWAP function");

  prettyPrint(CODE_INSTRUCTIONS, "ft::vector<int> foo(3,100);");
  prettyPrint(CODE_INSTRUCTIONS, "ft::vector<int> bar(5,200);");

  ft::vector<int> foo(3,100);   // three ints with a value of 100
  ft::vector<int> bar(5,200);   // five ints with a value of 200

  prettyPrint(CODE_INSTRUCTIONS, "foo.swap(bar);");
  foo.swap(bar);

  std::cout << "foo contains:";
  printVector(foo, true, true);

  std::cout << "bar contains:";
  printVector(bar, true, true);

  prettyPrint(CODE_INSTRUCTIONS, "ft::vector<std::string> foo2(1000, 'hello');");
  prettyPrint(CODE_INSTRUCTIONS, "ft::vector<std::string> bar2(250, 'bye');");
  ft::vector<std::string> foo2(1000, "hello");
  ft::vector<std::string> bar2(250, "bye");

  std::cout << "foo2 contains:";
  printVector(foo2, true, true);

  std::cout << "bar2 contains:";
  printVector(bar2, true, true);

}

