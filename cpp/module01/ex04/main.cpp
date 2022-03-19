/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 08:22:29 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/19 18:38:16 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int  errorMessage(std::string msg)
{
  std::cerr << "Error: " << msg << std::endl;
  std::cout << "arg1: filename | arg2: string1 | arg3: string2" << std::endl;
  return (1);
}

std::string replacer(std::string line, std::string s1, std::string s2)
{
  std::string result = line;
  size_t s1Length = s1.length();

  for (size_t  pos = 0; pos < line.length(); pos++)
  {
    if (line.compare(pos, s1Length, s1) == 0)
    {
      result.erase(pos, s1Length);
      result.insert(pos, s2);
    }
  }
  return (result);
}

int main(int argc, char** argv)
{
  if (argc != 4) {
    return (errorMessage("missing args!"));
  }
  std::string fileName = argv[1];
  std::string s1 = argv[2];
  std::string s2 = argv[3];
  std::ifstream ifs;
  std::ofstream ofs;
  std::ifstream& ifsRef = ifs;
  std::string line;

  ifs.open(fileName);
  ofs.open(fileName + ".replace");

  if (!ifs.is_open()) {
    return (errorMessage("Error while opening file" + fileName));
  }

  while (std::getline(ifs, line)) {
    ofs << replacer(line, s1, s2) << std::endl;
  }
  ifsRef.close();
  ofs.close();

  return (0);
}
