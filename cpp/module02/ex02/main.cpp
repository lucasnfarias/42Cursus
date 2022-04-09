/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:05:39 by lniehues          #+#    #+#             */
/*   Updated: 2022/04/09 18:28:45 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.class.hpp"

int main( void ) {
  Fixed a;
  Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
  // Fixed c( Fixed( 10.1f ) / Fixed( 2 ) );

  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max( a, b ) << std::endl;
  // std::cout << c << std::endl;
  // std::cout << c-- << std::endl;
  // std::cout << --c << std::endl;
  // std::cout << Fixed::max( c, b ) << std::endl;

  return 0;
}
