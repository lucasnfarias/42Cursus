/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_and_upper_bound.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:03:56 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/24 21:19:38 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void  tests_lower_and_upper_bound()
{
  prettyPrint(SUBTITLE, "Test LOWER_BOUND and UPPER_BOUND function");

  prettyPrint(CODE_INSTRUCTIONS, "ft::map<char,int> mymap;");
  prettyPrint(CODE_INSTRUCTIONS, "ft::map<char,int>::iterator itlow, itup;");

  ft::map<char,int> mymap;
  ft::map<char,int>::iterator itlow, itup;

  prettyPrint(CODE_INSTRUCTIONS, "mymap['a'] = 20;");
  prettyPrint(CODE_INSTRUCTIONS, "mymap['b'] = 40;");
  prettyPrint(CODE_INSTRUCTIONS, "mymap['c'] = 60;");
  prettyPrint(CODE_INSTRUCTIONS, "mymap['d'] = 80;");
  prettyPrint(CODE_INSTRUCTIONS, "mymap['e'] = 100;");

  mymap['a'] = 20;
  mymap['b'] = 40;
  mymap['c'] = 60;
  mymap['d'] = 80;
  mymap['e'] = 100;

  prettyPrint(CODE_INSTRUCTIONS, "itlow = mymap.lower_bound('b');");
  prettyPrint(CODE_INSTRUCTIONS, "itup = mymap.upper_bound('d');");

  itlow = mymap.lower_bound('b');  // itlow points to b
  itup = mymap.upper_bound('d');   // itup points to e (not d!)

  prettyPrint(CODE_INSTRUCTIONS, "mymap.erase(itlow, itup);");

  mymap.erase(itlow, itup);        // erases [itlow,itup)

  printMap(mymap);

  ft::map<char,int>::const_iterator itlowConst, itupConst;

  itlowConst = mymap.lower_bound('a');
  itupConst = mymap.upper_bound('a');

  std::cout << itlowConst->first << ", " << itlowConst->second << std::endl;
  std::cout << itupConst->first << ", " << itupConst->second << std::endl;
}
