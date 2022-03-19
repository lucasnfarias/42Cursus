/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileSed.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:11:16 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/19 17:22:10 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "FileSed.hpp"

FileSed::FileSed(std::string inputFileName) : _inputFileName(inputFileName) {};

FileSed::~FileSed(void) {};

std::ifstream& FileSed::createInputStream(void) const {
  std::ifstream ifs(this->_inputFileName);

  return ifs;
};

void  FileSed::replaceStrToOutputFile(std::string s1, std::string s2) const {

};
