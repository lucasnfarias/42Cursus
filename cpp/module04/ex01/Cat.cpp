/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:08:18 by lniehues          #+#    #+#             */
/*   Updated: 2022/04/26 17:04:18 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat()
{
  std::cout << "CAT Default constructor called" << std::endl;
  _type = "Cat";
}

Cat::Cat( const Cat & src )
 :
  Animal(src)
{
  std::cout << "CAT Copy constructor called" << std::endl;
  *this = src;
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
		this->_type = rhs.getType();
    _brain = &(rhs.getBrain());
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

/* ************************************************************************** */
