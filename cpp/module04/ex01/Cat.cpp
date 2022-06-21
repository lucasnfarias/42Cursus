/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:08:18 by lniehues          #+#    #+#             */
/*   Updated: 2022/04/27 12:04:43 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <stdlib.h>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat()
{
  _type = "Cat";
  _brain = new Brain();
  std::cout << "CAT Default constructor called" << std::endl;
}

Cat::Cat( const Cat & src )
 :
  Animal(src)
{
  *this = src;
  std::cout << "CAT Copy constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
  std::cout << "CAT destructor called" << std::endl;
  delete _brain;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
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

void  Cat::makeSound() const
{
  std::cout << "meowwwwwwwwwww" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Brain & Cat::getBrain() const
{
  return *_brain;
}

void Cat::getIdea() const
{
  std::cout << "Thinking... " << _brain->_ideas[rand() % 100] << std::endl;
}

/* ************************************************************************** */
