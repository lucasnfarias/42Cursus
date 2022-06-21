/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:08:18 by lniehues          #+#    #+#             */
/*   Updated: 2022/04/25 16:59:02 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat()
{
  std::cout << "WRONGCAT Default constructor called" << std::endl;
  _type = "Wrong Cat";
}

WrongCat::WrongCat( const WrongCat & src )
 :
  WrongAnimal(src)
{
  std::cout << "WRONGCAT Copy constructor called" << std::endl;
  *this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat()
{
  std::cout << "WRONGCAT destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat &				WrongCat::operator=( WrongCat const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void  WrongCat::makeSound() const
{
  std::cout << "meowwwwwwwwwww" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
