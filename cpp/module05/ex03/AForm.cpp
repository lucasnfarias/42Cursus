/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:21:33 by lniehues          #+#    #+#             */
/*   Updated: 2022/05/02 21:50:29 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

const int AForm::_highestGrade = 1;
const int AForm::_lowestGrade = 150;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm()
  :
  _name("Insane burocratic default form"),
  _isSigned(false),
  _signGrade(75),
  _executionGrade(75)
{
  std::cout << "AForm Default constructor called" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int executionGrade)
  :
  _name(name),
  _isSigned(false),
  _signGrade(signGrade),
  _executionGrade(executionGrade)
{
  _gradeChecker();
  std::cout << "AForm Name&Grades constructor called" << std::endl;
}


AForm::AForm( const AForm & src )
  :
  _name(src.getName()),
  _signGrade(src.getSignGrade()),
  _executionGrade(src.getExecutionGrade())
{
  *this = src;
  std::cout << "AForm Copy constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm()
{
  std::cout << "AForm destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &				AForm::operator=( AForm const & rhs )
{
	if ( this != &rhs )
	{
    _isSigned = rhs.getIsSigned();
    _target = rhs.getTarget();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AForm const & i )
{
	o
  << "---" << std::endl
  << i.getName()
  << " Form"
  << std::endl
  << "# Sign grade: "
  << i.getSignGrade()
  << std::endl
  << "# Execution grade: "
  << i.getExecutionGrade()
  << std::endl
  << "# Signed: "
  << (i.getIsSigned() ? "YES" : "NO")
  << std::endl << "---" << std::endl
  << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

bool  AForm::execute(Bureaucrat const & executor) const
{
  if (!_isSigned)
    throw AForm::NoSignatureException();
  else if (executor.getGrade() > _executionGrade)
    throw AForm::GradeTooLowException();
  return true;
}


void  AForm::beSigned(Bureaucrat const & bureaucrat)
{
  if (bureaucrat.getGrade() <= getSignGrade())
    _isSigned = true;
  else
    throw AForm::GradeTooLowException();
}

void  AForm::_gradeChecker()
{
  if (_signGrade < AForm::_highestGrade || _executionGrade < AForm::_highestGrade)
    throw AForm::GradeTooHighException();
  else if (_signGrade > AForm::_lowestGrade || _executionGrade > AForm::_lowestGrade)
    throw AForm::GradeTooLowException();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string AForm::getName() const
{
  return _name;
}

bool  AForm::getIsSigned() const
{
  return _isSigned;
}

int AForm::getSignGrade() const
{
  return _signGrade;
}

int AForm::getExecutionGrade() const
{
  return _executionGrade;
}

std::string AForm::getTarget() const
{
  return _target;
}

void AForm::setTarget(std::string & target)
{
  if (target.length())
    _target = target;
}


/* ************************************************************************** */
