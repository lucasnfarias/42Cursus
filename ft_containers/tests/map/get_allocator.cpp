/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_allocator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:45:28 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/24 21:48:37 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void tests_get_allocator()
{
  prettyPrint(SUBTITLE, "Test GET_ALLOCATOR function");

  prettyPrint(CODE_INSTRUCTIONS, "int psize;");
  prettyPrint(CODE_INSTRUCTIONS, "ft::map<char,int> mymap;");
  prettyPrint(CODE_INSTRUCTIONS, "ft::pair<const char,int>* p;");

  int psize;
  ft::map<char,int> mymap;
  ft::pair<const char,int> *p;

  prettyPrint(CODE_INSTRUCTIONS, "p = mymap.get_allocator().allocate(5);");

  // allocate an array of 5 elements using mymap's allocator:
  p = mymap.get_allocator().allocate(5);

  prettyPrint(CODE_INSTRUCTIONS, "psize = sizeof(ft::map<char,int>::value_type) * 5;");

  // assign some values to array
  psize = sizeof(ft::map<char,int>::value_type) * 5;

  std::cout << "The allocated array has a size of " << psize << " bytes.\n";

  prettyPrint(CODE_INSTRUCTIONS, "mymap.get_allocator().deallocate(p, 5);");

  mymap.get_allocator().deallocate(p, 5);
}
