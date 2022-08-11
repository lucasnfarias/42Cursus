/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helpers.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:25:21 by lniehues          #+#    #+#             */
/*   Updated: 2022/08/10 21:02:51 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_main.hpp"

void prettyPrint(TextType textType, std::string str)
{
  switch (textType)
  {
    case TITLE:
      std::cout << "\n---------------------\n" << std::endl;
      std::cout << str << std::endl;
      std::cout << "\n---------------------\n";
      break;
    case SUBTITLE:
      std::cout << "\n#                   #\n" << std::endl;
      std::cout << str << std::endl;
      std::cout << "\n#                   #\n";
      break;
    case CODE_INSTRUCTIONS:
      std::cout << "\ncode instruction: " << str << std::endl;
      break;
    case RESULT:
      std::cout << "\nresult: " << str << std::endl;
      break;
    default:
      break;
  }
  std::cout << std::endl;
}
