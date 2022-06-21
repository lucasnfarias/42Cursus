/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:08:25 by lniehues          #+#    #+#             */
/*   Updated: 2022/04/27 12:25:14 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <stdlib.h>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
  _type = "Dog";
  _brain = new Brain();
  std::cout << "DOG Default constructor called" << std::endl;
}

Dog::Dog( const Dog & src )
 :
  AAnimal(src)
{
  *this = src;
  std::cout << "DOG Copy constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
  std::cout << "DOG destructor called" << std::endl;
  delete _brain;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & rhs )
{
	if ( this != &rhs )
	{
		_type = rhs.getType();
    _brain = new Brain(rhs.getBrain());
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void  Dog::makeSound() const
{
  std::cout << "wolf wolf!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Brain & Dog::getBrain() const
{
  return *_brain;
}

void Dog::getIdea() const
{
  std::cout << "Thinking... " << _brain->_ideas[rand() % 100] << std::endl;
}

/* ************************************************************************** */
