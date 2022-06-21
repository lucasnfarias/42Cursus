/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileSed.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:05:52 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/25 21:45:01 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILESED_HPP
# define FILESED_HPP
# include <iostream>

class FileSed
{
private:
  std::string _inputFileName;
  std::ifstream _inputFile;

public:
  FileSed(std::string inputFileName);
  ~FileSed(void);

  std::string replacer(std::string line, std::string s1, std::string s2);
  int replaceStrToOutputFile(std::string s1, std::string s2);
};

int  errorMessage(std::string msg, bool print_args);

#endif
