/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:09:47 by lniehues          #+#    #+#             */
/*   Updated: 2022/04/25 16:54:07 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAnimal::WrongAnimal()
  :
  _type("Wrong Unicorn")
{
  std::cout << "WRONGANIMAL Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal & src )
{
  std::cout << "WRONGANIMAL Copy constructor called" << std::endl;
  *this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal()
{
  std::cout << "WRONGANIMAL destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal &				WrongAnimal::operator=( WrongAnimal const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, WrongAnimal const & i )
{
	o << "Value = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void  WrongAnimal::makeSound() const
{
  std::cout << "** weird WRONG noise **" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string WrongAnimal::getType() const
{
  return _type;
}

/* ************************************************************************** */
