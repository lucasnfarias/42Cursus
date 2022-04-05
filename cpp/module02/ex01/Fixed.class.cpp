/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:55:26 by lniehues          #+#    #+#             */
/*   Updated: 2022/04/01 20:05:26 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"
#include <iostream>

Fixed::Fixed( void ) : _fixedPointNumber(0)
{
  std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed( Fixed const & src )
{
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
};

Fixed::Fixed( int const i ) {};
Fixed::Fixed( float const f ) {};

Fixed::~Fixed( void )
{
  std::cout << "Destructor called" << std::endl;
};


Fixed & Fixed::operator=(Fixed const & rhs )
{
  std::cout << "Copy assignment operator called" << std::endl;
  this->_fixedPointNumber = rhs.getRawBits();
  return *this;
};


int Fixed:: getRawBits( void ) const
{
  std::cout << "getRawBits member function called" << std::endl;
  return this->_fixedPointNumber;
};

void Fixed::setRawBits( int const raw ) {
  this->_fixedPointNumber = raw;
};

float Fixed::toFloat( void ) const {};
int Fixed::toInt( void ) const {};

const int Fixed::_numOfFractionalBits = 8;
