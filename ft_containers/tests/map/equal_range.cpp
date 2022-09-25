/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal_range.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:25:07 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/24 21:43:21 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void  tests_equal_range()
{
  prettyPrint(SUBTITLE, "Test EQUAL_RANGE function");

  prettyPrint(CODE_INSTRUCTIONS, "ft::map<char,int> mymap;");
  ft::map<char,int> mymap;

  prettyPrint(CODE_INSTRUCTIONS, "mymap['a'] = 10;");
  prettyPrint(CODE_INSTRUCTIONS, "mymap['b'] = 20;");
  prettyPrint(CODE_INSTRUCTIONS, "mymap['c'] = 30;");

  mymap['a'] = 10;
  mymap['b'] = 20;
  mymap['c'] = 30;

  prettyPrint(CODE_INSTRUCTIONS, "ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;");
  prettyPrint(CODE_INSTRUCTIONS, "ret = mymap.equal_range('b');");

  ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
  ret = mymap.equal_range('b');

  std::cout << "lower bound points to: ";
  std::cout << ret.first->first << " => " << ret.first->second << '\n';

  std::cout << "upper bound points to: ";
  std::cout << ret.second->first << " => " << ret.second->second << '\n';
}
