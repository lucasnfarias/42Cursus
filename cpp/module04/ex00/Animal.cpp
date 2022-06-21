/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:09:47 by lniehues          #+#    #+#             */
/*   Updated: 2022/04/25 16:54:07 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal()
  :
  _type("Unicorn")
{
  std::cout << "ANIMAL Default constructor called" << std::endl;
}

Animal::Animal( const Animal & src )
{
  std::cout << "ANIMAL Copy constructor called" << std::endl;
  *this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
  std::cout << "ANIMAL destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &				Animal::operator=( Animal const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Animal const & i )
{
	o << "Value = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void  Animal::makeSound() const
{
  std::cout << "** weird noise **" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Animal::getType() const
{
  return _type;
}

/* ************************************************************************** */
