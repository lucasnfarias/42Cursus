/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_access_operator.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:20:48 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/21 13:06:41 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void  tests_element_access_operator()
{
  prettyPrint(SUBTITLE, "Test ELEMENT ACCESS OPERATOR function");

  prettyPrint(CODE_INSTRUCTIONS, "map<std::string,std::string> namesAndLastNames;");
  ft::map<std::string, std::string> namesAndLastNames;

  prettyPrint(CODE_INSTRUCTIONS, "namesAndLastNames['Lucas'] = 'Farias';");
  namesAndLastNames["Lucas"] = "Farias";
  prettyPrint(CODE_INSTRUCTIONS, "namesAndLastNames['Thomas'] = 'Bayes';");
  namesAndLastNames["Thomas"] = "Bayes";
  prettyPrint(CODE_INSTRUCTIONS, "namesAndLastNames['Ada'] = 'Lovelace';");
  namesAndLastNames["Ada"] = "Lovelace";
  prettyPrint(CODE_INSTRUCTIONS, "namesAndLastNames['Thiago'] = namesAndLastNames['Lucas'];");
  namesAndLastNames["Thiago"] = namesAndLastNames["Lucas"];
  prettyPrint(CODE_INSTRUCTIONS, "namesAndLastNames['Lucas'] = 'Niehues';");
  namesAndLastNames["Lucas"] = "Niehues";

  printMap(namesAndLastNames, true);

}
