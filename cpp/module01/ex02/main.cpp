/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 08:22:29 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/17 08:28:08 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main( void ) {
  std::string string =  "HI THIS IS BRAIN";
  std::string* stringPTR = &string;
  std::string& stringREF = string;

  std::cout << "string memory address: " << &string << std::endl;
  std::cout << "stringPTR memory address: " << stringPTR << std::endl;
  std::cout << "stringREF memory address: " << &stringREF << std::endl;
  std::cout << std::endl;
  std::cout << "string value: " << string << std::endl;
  std::cout << "stringPTR value: " << *stringPTR << std::endl;
  std::cout << "stringREF value: " << stringREF << std::endl;

  return (0);
}
