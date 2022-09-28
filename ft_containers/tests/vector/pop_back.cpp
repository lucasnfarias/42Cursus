/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_back.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:20:48 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/27 21:23:18 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void  tests_pop_back()
{
  prettyPrint(SUBTITLE, "Test POP_BACK function");

  prettyPrint(CODE_INSTRUCTIONS, "ft::vector<double> doubles;");
  ft::vector<double> doubles;

  prettyPrint(CODE_INSTRUCTIONS, "doubles.push_back(std::string); 7 times");

  doubles.push_back(42);
  doubles.push_back(21.222);
  doubles.push_back(-1231231.1211);
  doubles.push_back(111111111);
  doubles.push_back(-42);
  doubles.push_back(21.2);
  doubles.push_back(99999.6);

  printVector(doubles, true, true);

  prettyPrint(CODE_INSTRUCTIONS, "doubles.pop_back();");
  doubles.pop_back();

  prettyPrint(CODE_INSTRUCTIONS, "doubles.pop_back();");
  doubles.pop_back();

  printVector(doubles, true, true);

}
