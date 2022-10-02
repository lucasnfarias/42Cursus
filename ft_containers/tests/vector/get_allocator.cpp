/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_allocator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:20:48 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/27 21:33:46 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void  tests_get_allocator()
{
  prettyPrint(SUBTITLE, "Test GET_ALLOCATOR function");


  prettyPrint(CODE_INSTRUCTIONS, "vector<int> ints;");
  prettyPrint(CODE_INSTRUCTIONS, "int * p;");
  prettyPrint(CODE_INSTRUCTIONS, "unsigned int i;");
  ft::vector<int> myvector;
  int * p;
  unsigned int i;

  prettyPrint(CODE_INSTRUCTIONS, "p = myvector.get_allocator().allocate(5);");
  // allocate an array with space for 5 elements using vector's allocator:
  p = myvector.get_allocator().allocate(5);

  prettyPrint(CODE_INSTRUCTIONS, "for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);");
  // construct values in-place on the array:
  for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

  std::cout << "The allocated array contains:";
  for (i=0; i<5; i++) std::cout << ' ' << p[i];
  std::cout << '\n';

  // destroy and deallocate:
  for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
  myvector.get_allocator().deallocate(p,5);

}
