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
#include <cmath>

int ft_pow(int val, int pow)
{
  int res = 1;

  for (int i = 0; i < pow; i++)
  {
    res *= val;
  }
  return (res);
}

Fixed::Fixed( void ) : _fixedPointValue(0)
{
  std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed( Fixed const & src )
{
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
};

Fixed::Fixed( int const i ) {
  std::cout << "Int constructor called" << std::endl;
  this->_fixedPointValue = i << this->_numOfFractionalBits;
};

Fixed::Fixed( float const f ) {
  std::cout << "Float constructor called" << std::endl;
  this->_fixedPointValue = roundf(f * ft_pow(2, this->_numOfFractionalBits));
};

Fixed::~Fixed( void )
{
  std::cout << "Destructor called" << std::endl;
};


Fixed & Fixed::operator=(Fixed const & rhs )
{
  std::cout << "Copy assignment operator called" << std::endl;
  this->_fixedPointValue = rhs._fixedPointValue;
  return *this;
};


int Fixed:: getRawBits( void ) const
{
  std::cout << "getRawBits member function called" << std::endl;
  return this->_fixedPointValue;
};

void Fixed::setRawBits( int const raw ) {
  this->_fixedPointValue = raw;
};

float Fixed::toFloat( void ) const {
  return ((float) this->_fixedPointValue / ft_pow(2, this->_numOfFractionalBits));
};

int Fixed::toInt( void ) const {
  return (this->_fixedPointValue >> this->_numOfFractionalBits);
};

std::ostream & operator<<( std::ostream & o, Fixed const & f )
{
  o << f.toFloat();

  return o;
};

const int Fixed::_numOfFractionalBits = 8;
