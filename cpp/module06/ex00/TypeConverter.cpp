/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeConverter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 15:09:16 by lniehues          #+#    #+#             */
/*   Updated: 2022/05/13 20:49:28 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TypeConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

TypeConverter::TypeConverter( std::string input ) : _input(input)
{
}

TypeConverter::TypeConverter( const TypeConverter & src )
{
  *this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

TypeConverter::~TypeConverter()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

TypeConverter &				TypeConverter::operator=( TypeConverter const & rhs )
{
  (void)rhs;
  if (this != &rhs)
    this->_input = rhs.getInput();
	return *this;
}

std::ostream &			operator<<( std::ostream & o, TypeConverter const & i )
{
	o
  << "Bro... i'm just a regular type converter. This is my input: "
  << i.getInput()
  << ". See ya!";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void  TypeConverter::validate() const
{
  _validateChar();
  _validateInt();
  _validateFloat();
  _validateDouble();
}

void  TypeConverter::_validateChar() const
{}

void  TypeConverter::_validateInt() const
{}

void  TypeConverter::_validateFloat() const
{}

void  TypeConverter::_validateDouble() const
{}


void  TypeConverter::convert() const
{
  // char    c;
  int     i = toInt();
  // float   f;
  // double  d;

  std::cout << "int: " << i << std::endl;
}

char  TypeConverter::toChar() const
{
  // char convertedValue = dynamic_cast<char>(value);
  // std::cout << "char: ";
  // if (!convertedValue)
  //   std::cout << "impossible";
  // else
  //   std::cout << convertedValue;
  // std::cout << std::endl;
  return 'a';
}

int  TypeConverter::toInt() const
{
  // - if it is a char it will be 0 - need to check e.g value = 'a'
  // - check overflows
  return static_cast<int>(_input[0]);
}

float  TypeConverter::toFloat() const
{
  // float convertedValue = dynamic_cast<float>(value);
  // std::cout << "float: ";
  // if (!convertedValue)
  //   std::cout << "impossible";
  // else
  //   std::cout << convertedValue;
  // std::cout << std::endl;
  return static_cast<float>(_input[0]);
}

double  TypeConverter::toDouble() const
{
  // double convertedValue = dynamic_cast<double>(value);
  // std::cout << "double: ";
  // if (!convertedValue)
  //   std::cout << "impossible";
  // else
  //   std::cout << convertedValue;
  // std::cout << std::endl;
  return static_cast<double>(_input[0]);
}



/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string  TypeConverter::getInput() const
{
  return _input;
}



/* ************************************************************************** */
