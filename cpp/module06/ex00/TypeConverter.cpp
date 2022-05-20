/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeConverter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 15:09:16 by lniehues          #+#    #+#             */
/*   Updated: 2022/05/20 13:16:38 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TypeConverter.hpp"
#include <iomanip>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

TypeConverter::TypeConverter(std::string input) : _input(input), _type(NONE)
{
}

TypeConverter::TypeConverter(const TypeConverter &src)
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

TypeConverter &TypeConverter::operator=(TypeConverter const &rhs)
{
  (void)rhs;
  if (this != &rhs)
  {
    this->_input = rhs.getInput();
    this->_input = rhs.getType();
  }
  return *this;
}

std::ostream &operator<<(std::ostream &o, TypeConverter const &i)
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

void TypeConverter::validate()
{
  _createLog(Info, "Starting input type validation...");
  if (
      !_validateInt() &&
      !_validateFloat() &&
      !_validateDouble() &&
      !_validateChar())
    throw NotValidInput();
}

bool TypeConverter::_validateChar()
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
    _type = CHAR;
    return true;
  }
  return false;
}

bool TypeConverter::_validateInt()
{
  std::string input = getInput();
  size_t i = 0;

  if (input[i] == '+' || input[i] == '-')
    i++;
  while (i < input.length())
  {
    if (!isdigit(input[i]))
      return false;
    i++;
  }
  _createLog(Info, "A cheeky INT appears.");
  _type = INT;
  return true;
}

bool TypeConverter::_validateFloat()
{
  // check if valid 0f, .f, .3f,
  // check if necessary to have dot
  std::string input = getInput();
  size_t i = 0;
  size_t dotCount = 0;

  if (input == "-inff" || input == "+inff" || input == "nanf")
  {
    _createLog(Info, "A cheeky pseudo literal FLOAT appears.");
    _type = PSEUDO_LITERAL;
    return true;
  }
  if (input[input.length() - 1] != 'f')
    return false;
  if (input[i] == '+' || input[i] == '-')
    i++;
  while (i < input.length())
  {
    if (input[i] == '.' && isdigit(input[i + 1]))
    {
      i++;
      dotCount++;
    }
    else if (isdigit(input[i]) || (input[i] == 'f' && input[i + 1] == '\0'))
      i++;
    else
      return false;
  }
  if (dotCount == 1)
  {
    _createLog(Info, "A cheeky pseudo literal FLOAT appears.");
    _type = FLOAT;
    return true;
  }
  return false;
}

bool TypeConverter::_validateDouble()
{
  // check if valid 0, ., .3,
  // check if necessary to have dot
  std::string input = getInput();
  size_t i = 0;
  size_t dotCount = 0;

  if (input == "-inf" || input == "+inf" || input == "nan")
  {
    _createLog(Info, "A cheeky pseudo literal DOUBLE appears.");
    _type = PSEUDO_LITERAL;
    return true;
  }
  if (input[i] == '+' || input[i] == '-')
    i++;
  while (i < input.length())
  {
    if (input[i] == '.' && isdigit(input[i + 1]))
    {
      i++;
      dotCount++;
    }
    else if (isdigit(input[i]))
      i++;
    else
      return false;
  }
  if (dotCount == 1)
  {
    _createLog(Info, "A cheeky pseudo literal DOUBLE appears.");
    _type = DOUBLE;
    return true;
  }
  return false;
}

void TypeConverter::convert() const
{
  std::cout << std::fixed << std::setprecision(1);
  if (_type == PSEUDO_LITERAL)
    fromPseudoLiteral();
  // float   f;
  // double  d;
}

void TypeConverter::fromPseudoLiteral() const
{
  std::string input = getInput();
  _printValue("char");
  _printValue("int");
  if (input == "-inff" || input == "+inff" || input == "nanf")
  {
    _printValue("float", input);
    _printValue("double", input.length() == 4 ? input.substr(0, 3) : input.substr(0, 4)); // cut f out
    return;
  }
  _printValue("float", input + "f");
  _printValue("double", input);
}

void TypeConverter::fromChar() const
{
  // char convertedValue = dynamic_cast<char>(value);
  // std::cout << "char: ";
  // if (!convertedValue)
  //   std::cout << "impossible";
  // else
  //   std::cout << convertedValue;
  // std::cout << std::endl;
}

void TypeConverter::fromInt() const
{
  // - if it is a char it will be 0 - need to check e.g value = 'a'
  // - check overflows
}

void TypeConverter::fromFloat() const
{
  // float convertedValue = dynamic_cast<float>(value);
  // std::cout << "float: ";
  // if (!convertedValue)
  //   std::cout << "impossible";
  // else
  //   std::cout << convertedValue;
  // std::cout << std::endl;
}

void TypeConverter::fromDouble() const
{
  // double convertedValue = dynamic_cast<double>(value);
  // std::cout << "double: ";
  // if (!convertedValue)
  //   std::cout << "impossible";
  // else
  //   std::cout << convertedValue;
  // std::cout << std::endl;
}

void TypeConverter::_createLog(LogLevel level, std::string message) const
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

void TypeConverter::_printValue(std::string type, std::string value) const
{
  std::cout << type << ": " << value << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string TypeConverter::getInput() const
{
  return _input;
}

inputType TypeConverter::getType() const
{
  return _type;
}

/* ************************************************************************** */
