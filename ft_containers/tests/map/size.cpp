/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:20:48 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/20 13:00:20 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void  tests_size()
{
  prettyPrint(SUBTITLE, "Test SIZE function");

  prettyPrint(CODE_INSTRUCTIONS, "map<std::string, int> namesAndNumbers;");
  ft::map<std::string, int> namesAndNumbers;

  prettyPrint(CODE_INSTRUCTIONS, "namesAndNumbers.size();");
  prettyPrint(RESULT, namesAndNumbers.size());

  prettyPrint(CODE_INSTRUCTIONS, "namesAndNumbers['Lucas'] = 1;");
  namesAndNumbers["Lucas"] = 1;

  prettyPrint(CODE_INSTRUCTIONS, "namesAndNumbers.size();");
  prettyPrint(RESULT, namesAndNumbers.size());

  prettyPrint(CODE_INSTRUCTIONS, "namesAndNumbers['Casemiro'] = -2;");
  prettyPrint(CODE_INSTRUCTIONS, "namesAndNumbers['Pirineu'] = 42;");
  namesAndNumbers["Casemiro"] = -2;
  namesAndNumbers["Pirineu"] = 42;

  prettyPrint(CODE_INSTRUCTIONS, "namesAndNumbers.size();");
  prettyPrint(RESULT, namesAndNumbers.size());
}
