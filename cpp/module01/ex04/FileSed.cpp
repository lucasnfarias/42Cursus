/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileSed.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:11:16 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/27 21:59:47 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include "FileSed.hpp"

int errorMessage(std::string msg, bool print_args)
{
  std::cerr << "Error: " << msg << std::endl;
  if (print_args)
    std::cout << "arg1: filename | arg2: string1 | arg3: string2" << std::endl;
  return (1);
}

FileSed::FileSed(std::string inputFileName) : _inputFileName(inputFileName)
{
  this->_inputFile.open(inputFileName.c_str());
  std::cout << "Input file set to " << inputFileName << std::endl;
};

FileSed::~FileSed(void){};

std::string FileSed::replacer(std::string line, std::string s1, std::string s2)
{
  std::string result;
  size_t s1Length = s1.length();

  result.assign(line);
  if (s1.length() == 0)
    return (result);

  for (size_t pos = 0; pos < result.length(); pos++)
  {
    if (result.compare(pos, s1Length, s1) == 0)
    {
      result.erase(pos, s1Length);
      result.insert(pos, s2);
    }
  }
  return (result);
}

int FileSed::replaceStrToOutputFile(std::string s1, std::string s2)
{
  std::ofstream ofs;
  std::string line;

  if (!this->_inputFile.is_open())
  {
    return (errorMessage("could not open file " + this->_inputFileName, false));
  }
  std::string ofsName = this->_inputFileName + ".replace";

  ofs.open(ofsName.c_str());

  while (std::getline(this->_inputFile, line))
  {
    ofs << this->replacer(line, s1, s2) << std::endl;
  }
  ofs.close();

  return (0);
};
