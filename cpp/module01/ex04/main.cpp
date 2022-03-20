/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 08:22:29 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/20 20:17:37 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "FileSed.hpp"

int main(int argc, char** argv)
{
  if (argc != 4) {
    return (errorMessage("missing args!"));
  }

  std::string fileName = argv[1];
  std::string s1 = argv[2];
  std::string s2 = argv[3];
  FileSed fileSed(fileName);

  return (fileSed.replaceStrToOutputFile(s1, s2));
}
