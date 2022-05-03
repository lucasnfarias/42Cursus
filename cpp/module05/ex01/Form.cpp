/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:21:33 by lniehues          #+#    #+#             */
/*   Updated: 2022/05/02 21:50:29 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

const int Form::_highestGrade = 1;
const int Form::_lowestGrade = 150;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form()
  :
  _name("Insane burocratic default form"),
  _isSigned(false),
  _signGrade(75),
  _executionGrade(75)
{
  std::cout << "Form Default constructor called" << std::endl;
}

Form::Form(std::string name, int signGrade, int executionGrade)
  :
  _name(name),
  _isSigned(false),
  _signGrade(signGrade),
  _executionGrade(executionGrade)
{
  _gradeChecker();
  std::cout << "Form Name&Grades constructor called" << std::endl;
}


Form::Form( const Form & src )
  :
  _name(src.getName()),
  _signGrade(src.getSignGrade()),
  _executionGrade(src.getExecutionGrade())
{
  *this = src;
  std::cout << "Form Copy constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
  std::cout << "Form destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
    this->_isSigned = rhs.getIsSigned();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o
  << i.getName()
  << ", form sign grade "
  << i.getSignGrade()
  << ", execution grade "
  << i.getExecutionGrade()
  << " and is"
  << (i.getIsSigned() ? " " : " NOT ")
  << "signed."
  << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void  Form::beSigned(Bureaucrat & bureaucrat)
{
  if (bureaucrat.getGrade() <= getSignGrade())
    _isSigned = true;
  else
    throw Form::GradeTooLowException();
}

void  Form::_gradeChecker()
{
  if (_signGrade < Form::_highestGrade || _executionGrade < Form::_highestGrade)
    throw Form::GradeTooHighException();
  else if (_signGrade > Form::_lowestGrade || _executionGrade > Form::_lowestGrade)
    throw Form::GradeTooLowException();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string Form::getName() const
{
  return _name;
}

bool  Form::getIsSigned() const
{
  return _isSigned;
}

int Form::getSignGrade() const
{
  return _signGrade;
}

int Form::getExecutionGrade() const
{
  return _executionGrade;
}


/* ************************************************************************** */
