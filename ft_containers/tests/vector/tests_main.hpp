#ifndef TESTS_MAIN_HPP
# define TESTS_MAIN_HPP

// PROBABLY MOVE COLORS AND PRINT HELPERS TO TESTS ROOT AND UPDATE MAKEFILE TO USE IT

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define RESET "\033[0m"

# include <iostream>
# include <stdlib.h>
# include <algorithm>

#ifdef STD_VERSION
	#define VERSION "STD_VERSION"
	#include <vector>
  namespace ft = std;
#else
	#define VERSION "FT_VERSION"
	#include "../../containers/vector.hpp"
#endif

// PRINT HELPERS

enum TextType { TITLE = 0, SUBTITLE = 1, CODE_INSTRUCTIONS = 2, RESULT = 3, DESCRIPTION = 4 };

template <typename T>
void prettyPrint(TextType textType, T value)
{
  switch (textType)
  {
    case TITLE:
      std::cout
        << PURPLE
        << "\n---------------------\n" << std::endl
        << value << std::endl
        << "\n---------------------\n" << RESET;
      break;
    case SUBTITLE:
      std::cout
        << YELLOW
        << "\n#                   #\n" << std::endl
        << value << std::endl
        << "\n#                   #\n" << RESET;
      break;
    case DESCRIPTION:
      std::cout << YELLOW << "\ntest description: " << value << RESET << std::endl;
      break;
    case CODE_INSTRUCTIONS:
      std::cout << CYAN << "\ncode instruction: " << value << RESET << std::endl;
      break;
    case RESULT:
      std::cout << GREEN << "result: " << value << RESET << std::endl;
      break;
    default:
      break;
  }
  std::cout << std::endl;
}

template <typename T>
void printVector(const ft::vector<T> &vect, bool printInline = false, bool printAttributes = false)
{
  std::cout << "vector data: " << (vect.size() ? "" : "- empty -") << std::endl;

  if (printAttributes) {
    std::cout << "- size: " << vect.size() << std::endl;
    std::cout << "- capacity: " << vect.capacity() << std::endl;
    std::cout << std::endl;
  }

  if (printInline) {
    size_t lastIndex = vect.size() - 1;
    for (size_t i = 0; i < vect.size(); i++) {
      std::cout << vect[i] << (i == lastIndex ? "" : " | ");
    }
  } else {
      for (size_t i = 0; i < vect.size(); i++) {
        std::cout << "vector[" << i << "] = " << vect[i] << std::endl;
      }
  }
  std::cout << std::endl;
}


// TESTS

void  tests_clear();
void  tests_empty();
void  tests_erase();
void  tests_resize();
void  tests_reserve();
void  tests_constructors();
void  tests_operators();
void  tests_iterators();

#endif
