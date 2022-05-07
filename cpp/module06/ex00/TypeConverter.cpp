/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeConverter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 15:09:16 by lniehues          #+#    #+#             */
/*   Updated: 2022/05/07 16:00:45 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TypeConverter.hpp"
#include <sstream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

TypeConverter::TypeConverter()
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
	return *this;
}

std::ostream &			operator<<( std::ostream & o, TypeConverter const & i )
{
  (void)i;
	o << "Bro... i'm just a regular type converter. See ya!";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void  TypeConverter::convertAll(char* value) const
{
  // char    c;
  int     i = toInt(value);
  // float   f;
  // double  d;

  std::cout << "int: " << i << std::endl;
}

char  TypeConverter::toChar(char* value) const
{
  (void)value;
  // char convertedValue = dynamic_cast<char>(value);
  // std::cout << "char: ";
  // if (!convertedValue)
  //   std::cout << "impossible";
  // else
  //   std::cout << convertedValue;
  // std::cout << std::endl;
  return 'a';
}

int  TypeConverter::toInt(char* value) const
{
  // - if it is a char it will be 0 - need to check e.g value = 'a'
  // - check overflows
  std::stringstream ss;
  int convertedValue;

  ss << value;
  ss >> convertedValue;

  return convertedValue;
}

float  TypeConverter::toFloat(char* value) const
{
  (void)value;
  // float convertedValue = dynamic_cast<float>(value);
  // std::cout << "float: ";
  // if (!convertedValue)
  //   std::cout << "impossible";
  // else
  //   std::cout << convertedValue;
  // std::cout << std::endl;
  return 1.2f;
}

double  TypeConverter::toDouble(char* value) const
{
  (void)value;
  // double convertedValue = dynamic_cast<double>(value);
  // std::cout << "double: ";
  // if (!convertedValue)
  //   std::cout << "impossible";
  // else
  //   std::cout << convertedValue;
  // std::cout << std::endl;
  return 1.2;
}



/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
