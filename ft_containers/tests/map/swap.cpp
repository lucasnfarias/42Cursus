/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:29:26 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/24 18:40:27 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void tests_swap()
{
  prettyPrint(SUBTITLE, "Test SWAP function");

  prettyPrint(CODE_INSTRUCTIONS, "ft::map<double,char> foo, bar;");

  ft::map<double,char> foo, bar;

  prettyPrint(CODE_INSTRUCTIONS, "foo[1.23] = 'b';");
  prettyPrint(CODE_INSTRUCTIONS, "foo[42.1] = 'z';");

  foo[1.23] = 'b';
  foo[42.1] = 'z';

  prettyPrint(CODE_INSTRUCTIONS, "bar[1.2] = 's';");
  prettyPrint(CODE_INSTRUCTIONS, "bar[1.456] = 'v';");
  prettyPrint(CODE_INSTRUCTIONS, "bar[-12.9] = 'u';");

  bar[1.2] = 's';
  bar[1.456] = 'v';
  bar[-12.9] = 'u';

  prettyPrint(CODE_INSTRUCTIONS, "foo.swap(bar);");

  foo.swap(bar);

  printMap(foo, false, "foo");
  printMap(bar, false, "bar");
}
