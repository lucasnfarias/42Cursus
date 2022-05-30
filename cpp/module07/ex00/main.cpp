/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 03:10:43 by coder             #+#    #+#             */
/*   Updated: 2022/05/30 23:53:33 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main( void ) {
  std::cout << "\n# TEST - DIFFERENT INTS - a: 2, b: 3\n" << std::endl;
  
  int a = 2;
  int b = 3;

  ::swap( a, b );
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
  std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

  std::cout << "\n# TEST - DIFFERENT STRINGS - c: chaine1, d: chaine2\n" << std::endl;

  std::string c = "chaine1";
  std::string d = "chaine2";

  ::swap(c, d);
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
  std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

  std::cout << "\n# TEST - EQUAL FLOAT s- x: 42, y: 42\n" << std::endl;

  float x = 42.0;
  float y = 42.0;

  ::swap( x, y );
  std::cout << "x = " << x << ", y = " << y << std::endl;
  std::cout << "min( x, y ) = " << ::min( x, y ) << std::endl;
  std::cout << "max( x, y ) = " << ::max( x, y ) << std::endl;

  return 0;
}