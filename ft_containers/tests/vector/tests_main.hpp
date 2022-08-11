#ifndef TESTS_MAIN_HPP
# define TESTS_MAIN_HPP

# include <iostream>
# include <stdlib.h>
# include <algorithm>

#ifdef STD_VERSION
	#define VERSION "STD_VERSION"
	#define ft std
	#include <vector>
#else
	#define VERSION "FT_VERSION"
	#include "../../containers/vector.hpp"
#endif

// PRINT HELPERS

enum TextType { TITLE = 0, SUBTITLE = 1, CODE_INSTRUCTIONS = 2, RESULT = 3 };

void  prettyPrint(TextType textType, std::string str);

template <typename T>
void printVector(ft::vector<T> vect, bool printInline = false)
{
  std::cout << "vector data: " << (vect.size() ? "" : "- empty -") << std::endl;

  if (printInline) {
    for (size_t i = 0; i < vect.size(); i++) {
      std::cout << vect[i] << " ";
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

#endif
