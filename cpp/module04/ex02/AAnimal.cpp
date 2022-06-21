/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:09:47 by lniehues          #+#    #+#             */
/*   Updated: 2022/04/27 12:03:10 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AAnimal::AAnimal()
  :
  _type("Unicorn")
{
  std::cout << "AANIMAL Default constructor called" << std::endl;
}

AAnimal::AAnimal( const AAnimal & src )
{
  std::cout << "AANIMAL Copy constructor called" << std::endl;
  *this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AAnimal::~AAnimal()
{
  std::cout << "AANIMAL destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AAnimal &				AAnimal::operator=( AAnimal const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AAnimal const & i )
{
	o << "Value = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string AAnimal::getType() const
{
  return _type;
}

/* ************************************************************************** */
