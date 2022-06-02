/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 03:10:43 by coder             #+#    #+#             */
/*   Updated: 2022/06/02 15:28:35 by lniehues         ###   ########.fr       */
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
  enterToContinue();

  std::cout << "\n# TEST - DIFFERENT STRINGS - c: chaine1, d: chaine2\n" << std::endl;

  std::string c = "chaine1";
  std::string d = "chaine2";

  ::swap(c, d);
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
  std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
  enterToContinue();

  std::cout << "\n# TEST - EQUAL FLOATS - x: 42, y: 42\n" << std::endl;

  float x = 42.0;
  float y = 42.0;

  ::swap( x, y );
  std::cout << "x = " << x << ", y = " << y << std::endl;
  std::cout << "min( x, y ) = " << ::min( x, y ) << std::endl;
  std::cout << "max( x, y ) = " << ::max( x, y ) << std::endl;
  enterToContinue();

  std::cout << "\n# TEST - CLASS EXAMPLE\n" << std::endl;

  Example test(21);
  Example test2(42);

  ::swap( test, test2 );
  std::cout << "test = " << test << ", test2 = " << test2 << std::endl;
  std::cout << "min( test, test2 ) = " << ::min( test, test2 ) << std::endl;
  std::cout << "max( test, test2 ) = " << ::max( test, test2 ) << std::endl;

  return 0;
}
