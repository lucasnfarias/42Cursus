/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:43:12 by lniehues          #+#    #+#             */
/*   Updated: 2022/04/01 19:53:11 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_POINT_HPP
# define FIXED_POINT_HPP

# include <iostream>

class Fixed {

public:
  Fixed( void );
  Fixed( Fixed const & src );
  Fixed( int const i );
  Fixed( float const f );
  ~Fixed( void );

  Fixed & operator=( Fixed const & rhs );

  bool operator>( Fixed const & rhs ) const;
  bool operator<( Fixed const & rhs ) const;
  bool operator>=( Fixed const & rhs ) const;
  bool operator<=( Fixed const & rhs ) const;
  bool operator==( Fixed const & rhs ) const;
  bool operator!=( Fixed const & rhs ) const;

  Fixed operator+( Fixed const & rhs ) const;
  Fixed operator-( Fixed const & rhs ) const;
  Fixed operator*( Fixed const & rhs ) const;
  Fixed operator/( Fixed const & rhs ) const;

  Fixed & operator++( void );
  Fixed operator++( int );
  Fixed & operator--( void );
  Fixed operator--( int );

  int getRawBits( void ) const;
  void setRawBits( int const raw );

  float toFloat( void ) const;
  int toInt( void ) const;

  static Fixed & min(Fixed & v1, Fixed & v2 );
  static Fixed const & min(Fixed const & v1, Fixed const & v2 );
  static Fixed & max(Fixed & v1, Fixed & v2 );
  static Fixed const & max(Fixed const & v1, Fixed const & v2 );

private:
  int _fixedPointValue;
  static const int _numOfFractionalBits;
};

std::ostream & operator<<( std::ostream & o, Fixed const & f );
int ft_pow(int val, int pow);

#endif
