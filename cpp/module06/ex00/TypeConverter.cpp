/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeConverter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 15:09:16 by lniehues          #+#    #+#             */
/*   Updated: 2022/05/25 20:37:20 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TypeConverter.hpp"
#include <iomanip>
#include <limits.h>
#include <stdlib.h>
#include <float.h>
#include <errno.h>

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

/* ------- VALIDATION METHODS ------- */

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
  if (i == 1 && input.length() == 1)
    return false;
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

bool  TypeConverter::_hasOverflow() const
{
  errno = 0;
  double checkValue = strtod(_input.c_str(), NULL);

  if (errno == ERANGE)
    return true;
  switch (_type)
  {
  case INT:
    if (checkValue < -DBL_MAX || checkValue > INT_MAX)
      return true;
    break;
  case FLOAT:
    if (checkValue < -FLT_MAX || checkValue > FLT_MAX)
      return true;
    break;
  case DOUBLE:
    if (checkValue < -DBL_MAX || checkValue > DBL_MAX)
      return true;
    break;
  default:
    return false;
    break;
  }
  return false;
}

/* ------- CONVERSION METHODS ------- */

void TypeConverter::convert() const
{
  std::cout << std::fixed << std::setprecision(PRECISION);
  if (_type == PSEUDO_LITERAL)
    _fromPseudoLiteral();
  else if (_type == CHAR)
    _fromChar();
  else if (_type == INT)
    _fromInt();
  else if (_type == FLOAT)
    _fromFloat();
  else if (_type == DOUBLE)
    _fromDouble();
  else
    throw TypeConverter::NotValidInput();
}

void TypeConverter::_fromPseudoLiteral() const
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

void TypeConverter::_fromChar() const
{
  char  c = _input[0];
  _printValue("char", c);
  _printValue("int", static_cast<int>(c));
  _printValue("float", static_cast<float>(c));
  _printValue("double", static_cast<double>(c));
}

void TypeConverter::_fromInt() const
{
  if (_hasOverflow())
    return (_printImpossible());

  int i = atoi(_input.c_str());
  _fromNumberToChar(static_cast<char>(i));
  _fromNumberToInt(i);
  _fromNumberToFloat(static_cast<float>(i));
  _fromNumberToDouble(static_cast<double>(i));
}

void TypeConverter::_fromFloat() const
{
  if (_hasOverflow())
    return (_printImpossible());

  float f = atof(_input.c_str());
  _fromNumberToChar(static_cast<char>(f));
  _fromNumberToInt(static_cast<int>(f));
  _fromNumberToFloat(f);
  _fromNumberToDouble(static_cast<double>(f));
}

void TypeConverter::_fromDouble() const
{
  if (_hasOverflow())
    return (_printImpossible());

  double d = strtod(_input.c_str(), NULL);
  _fromNumberToChar(static_cast<char>(d));
  _fromNumberToInt(static_cast<int>(d));
  _fromNumberToFloat(static_cast<float>(d));
  _fromNumberToDouble(d);
}

void  TypeConverter::_fromNumberToChar(char c) const
{
  double checkValue = strtod(_input.c_str(), NULL);

  if (checkValue < 0 || checkValue > 127)
    _printValue("char");
  else
  {
    if (isprint(c)) // maybe this -> c >= '!' && c <= '~'
      _printValue("char", c);
    else
      _printValue("char", "Non displayable");
  }
}

void  TypeConverter::_fromNumberToInt(int i) const
{
  double checkValue = strtod(_input.c_str(), NULL);

  if (checkValue < INT_MIN || checkValue > INT_MAX)
    _printValue("int");
  else
    _printValue("int", i);
}

void  TypeConverter::_fromNumberToFloat(float f) const
{
  double checkValue = strtod(_input.c_str(), NULL);

  if (checkValue < -FLT_MAX || checkValue > FLT_MAX)
    _printValue("float");
  else
    _printValue("float", f);
}

void  TypeConverter::_fromNumberToDouble(double d) const
{
  double checkValue = strtod(_input.c_str(), NULL);

  if (checkValue < -DBL_MAX || checkValue > DBL_MAX)
    _printValue("double");
  else
    _printValue("double", d);
}


/* ------- PRINT METHODS ------- */

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

void  TypeConverter::_printValue(std::string type, char value) const
{
  std::cout << type << ": '" << value << "'" << std::endl;
}


void  TypeConverter::_printValue(std::string type, int value) const
{
  std::cout << type << ": " << value << std::endl;
}

void  TypeConverter::_printValue(std::string type, float value) const
{
  std::cout << type << ": " << value << "f" << std::endl;
}

void  TypeConverter::_printValue(std::string type, double value) const
{
  std::cout << type << ": " << value << std::endl;
}

void  TypeConverter::_printImpossible() const
{
  _printValue("char");
  _printValue("int");
  _printValue("float");
  _printValue("double");
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
