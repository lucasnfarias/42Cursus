/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 15:04:41 by lniehues          #+#    #+#             */
/*   Updated: 2022/05/25 21:20:03 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serializeSomeStuff.hpp"

static void initializeData(Data *data)
{
  data->s1 = "Don't Panic!";
  data->i = 42;
}

static void  printData(Data *data)
{
  std::cout
  << "s1: "
  << data->s1
  << std::endl
  << "i: "
  << data->i
  << std::endl
  << std::endl;
}

int main()
{
  Data *data = new Data();
  Data *deserializedData;
  uintptr_t serializedData;

  initializeData(data);
  std::cout << "--- Untouched Data ---" << std::endl;
  printData(data);

  serializedData = serialize(data);
  std::cout << "--- Data Serialized (uintptr_t) ---" << std::endl;
  std::cout << serializedData << std::endl << std::endl;

  deserializedData = deserialize(serializedData);
  std::cout << "--- Deserialized Data ---" << std::endl;
  printData(deserializedData);

  delete data;
}
