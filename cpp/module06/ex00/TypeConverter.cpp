/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeConverter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 15:09:16 by lniehues          #+#    #+#             */
/*   Updated: 2022/05/18 20:41:16 by lniehues         ###   ########.fr       */
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
  if (
    !_validateInt() &&
    !_validateFloat() &&
    !_validateDouble() &&
    !_validateChar()
  )
    throw NotValidInput();
}

bool  TypeConverter::_validateChar() const
{
  std::string input = getInput();

  if (input.length() == 1)
  {
    if (!isprint(input[0]))
    {
      _createLog(Warning, "Input is a non-displayable char.");
      return false;
    }
    _createLog(Info, "A cheeky displayable CHAR appears.");
    return true;
  }
  _createLog(Warning, "Not a char.");
  return false;
}

bool  TypeConverter::_validateInt() const
{
  std::string input = getInput();
  size_t i = 0;

  if (input[i] == '+' || input[i] == '-')
    i++;
  while (i < input.length())
  {
    if (!isdigit(input[0]))
    {
      _createLog(Warning, "Not a int.");
      return false;
    }
    i++;
  }
  _createLog(Info, "A cheeky INT appears.");
  return true;
}

bool  TypeConverter::_validateFloat() const
{
  std::string input = getInput();
  size_t i = 0;
	// size_t count = 0;

  if (input == "-inff" || input == "+inff" || input == "nanf")
  {
    _createLog(Info, "A cheeky pseudo literal FLOAT appears.");
    return true;
  }
  if (input[i] == '+' || input[i] == '-')
    i++;
  _createLog(Warning, "Not a float.");
  return false;
}

bool  TypeConverter::_validateDouble() const
{
  _createLog(Warning, "Not a double.");
  return false;
}


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

void  TypeConverter::_createLog(LogLevel level, std::string message) const
{
  std::string logPrefix;

  switch (level)
  {
  case Error:
    logPrefix.append(RED);
    logPrefix.append("[ERROR] ");
    break;
  case Warning:
    logPrefix.append(YELLOW);
    logPrefix.append("[WARNING] ");
    break;
  case Info:
    logPrefix.append(PURPLE);
    logPrefix.append("[INFO] ");
    break;
  default:
    break;
  }

  std::cout
  << logPrefix
  << message
  << RESET
  << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string  TypeConverter::getInput() const
{
  return _input;
}



/* ************************************************************************** */
