/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 18:05:57 by lniehues          #+#    #+#             */
/*   Updated: 2022/05/02 20:13:45 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <stdexcept>

const int Bureaucrat::_highestGrade = 1;
const int Bureaucrat::_lowestGrade = 150;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : _name("Capote"), _grade(75)
{
  std::cout << "Created bureaucrat Capote with grade 75 ;)" << std::endl;
  std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name), _grade(grade)
{
  _gradeChecker();
  std::cout << "Bureaucrat NameGrade constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ) : _name(src.getName())
{
  *this = src;
  std::cout << "Bureaucrat Copy constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
  std::cout << "Bureaucrat destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if ( this != &rhs )
	{
		this->_grade = rhs.getGrade();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Bureaucrat::incrementGrade()
{
  try
  {
    _grade--;
    _gradeChecker();
  }
  catch (std::exception& e)
  {
    _grade++;
    std::cerr << "Not able to increment " << _name << std::endl;
    std::cerr << e.what() << std::endl;
  }
}

void Bureaucrat::decrementGrade()
{
  try
  {
    _grade++;
    _gradeChecker();
  }
  catch (std::exception& e)
  {
    _grade--;
    std::cerr << "Not able to decrement " << _name << std::endl;
    std::cerr << e.what() << std::endl;
  }
}

void  Bureaucrat::_gradeChecker()
{
  if (_grade < Bureaucrat::_highestGrade)
    throw Bureaucrat::GradeTooHighException();
  else if (_grade > Bureaucrat::_lowestGrade)
    throw Bureaucrat::GradeTooLowException();
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string Bureaucrat::getName() const
{
  return _name;
}

int Bureaucrat::getGrade() const
{
  return _grade;
}


/* ************************************************************************** */
