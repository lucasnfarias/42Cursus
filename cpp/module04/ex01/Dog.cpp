/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:08:25 by lniehues          #+#    #+#             */
/*   Updated: 2022/04/26 17:04:23 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
  std::cout << "DOG Default constructor called" << std::endl;
  _type = "Dog";
  _brain = new Brain();
}

Dog::Dog( const Dog & src )
 :
  Animal(src)
{
  std::cout << "DOG Copy constructor called" << std::endl;
  *this = src;
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
    _brain = &(rhs.getBrain());
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


/* ************************************************************************** */
