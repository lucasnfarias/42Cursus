/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_main.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:44:51 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/14 16:24:02 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_MAIN_HPP
# define TESTS_MAIN_HPP

# define RED_COLOR "\033[0;31m"
# define GREEN_COLOR "\033[0;32m"
# define YELLOW_COLOR "\033[0;33m"
# define BLUE_COLOR "\033[0;34m"
# define PURPLE_COLOR "\033[0;35m"
# define CYAN_COLOR "\033[0;36m"
# define RESET_COLOR "\033[0m"

# include <iostream>
# include <stdlib.h>
# include <algorithm>

#ifdef STD_VERSION
	#define VERSION "STD_VERSION"
	#include <map>
  namespace ft = std;
#else
	#define VERSION "FT_VERSION"
	#include "../../containers/map.hpp"
#endif

// PRINT HELPERS

enum TextType { TITLE = 0, SUBTITLE = 1, CODE_INSTRUCTIONS = 2, RESULT = 3 };

template <typename T>
void prettyPrint(TextType textType, T value)
{
  switch (textType)
  {
    case TITLE:
      std::cout
        << PURPLE_COLOR
        << "\n---------------------\n" << std::endl
        << value << std::endl
        << "\n---------------------\n" << RESET_COLOR;
      break;
    case SUBTITLE:
      std::cout
        << YELLOW_COLOR
        << "\n#                   #\n" << std::endl
        << value << std::endl
        << "\n#                   #\n" << RESET_COLOR;
      break;
    case CODE_INSTRUCTIONS:
      std::cout << CYAN_COLOR << "\ncode instruction: " << value << RESET_COLOR << std::endl;
      break;
    case RESULT:
      std::cout << GREEN_COLOR << "result: " << value << RESET_COLOR << std::endl;
      break;
    default:
      break;
  }
  std::cout << std::endl;
}

template <typename Key, typename T>
void printMap(ft::map<Key, T> &my_map, bool printSize = false)
{
  std::cout << "map data: " << (my_map.size() ? "" : "- empty -") << std::endl;

  if (printSize) {
    std::cout << "- size: " << my_map.size() << std::endl;
    std::cout << std::endl;
  }

  for (typename ft::map<Key, T>::iterator it = my_map.begin(); it != my_map.end(); it++)
    std::cout << "map[" << it->first << "] = " << it->second << std::endl;
  std::cout << std::endl;
}


// TESTS

void  tests_empty();

#endif
