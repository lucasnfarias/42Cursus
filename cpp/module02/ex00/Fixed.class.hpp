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

class Fixed {

public:
  Fixed( void );
  Fixed( Fixed const & src );
  ~Fixed( void );

  Fixed & operator=(Fixed const & rhs );

  int getRawBits( void ) const;
  void setRawBits( int const raw );

private:
  int _fixedPointNumber;
  static const int _numOfFractionalBits;
};

#endif
