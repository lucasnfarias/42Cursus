/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileSed.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:05:52 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/19 17:17:52 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILESED_HPP
#define FILESED_HPP
#include <iostream>

class FileSed
{
private:
  std::string _inputFileName;

public:
  FileSed(std::string inputFileName);
  ~FileSed(void);

  std::ifstream &createInputStream(void) const;
  void replaceStrToOutputFile(std::string s1, std::string s2) const;
};

#endif
