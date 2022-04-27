/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:05:39 by lniehues          #+#    #+#             */
/*   Updated: 2022/04/27 12:10:32 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{

std::cout << "\n\n### TEST HEAP ANIMALS ###\n\n" << std::endl;

Animal* animals[10];

for (int i = 0; i < 5; i++)
{
  std::cout << "Animal " << i << ":" << std::endl;
  animals[i] = new Dog();
}
for (int i = 5; i < 10; i++)
{
  std::cout << "Animal " << i << ":" << std::endl;
  animals[i] = new Cat();
}

for (int i = 0; i < 10; i++)
{
  std::cout << "Animal " << i << ": " << animals[i]->getType() << " - ";
  animals[i]->makeSound();
  animals[i]->getIdea();
}

for (int i = 0; i < 10; i++)
{
  std::cout << "Animal " << i << ":" << std::endl;
  delete animals[i];
}

std::cout << "\n\n### TEST STACK ANIMALS ###\n\n" << std::endl;

const Dog dog = Dog();
const Cat cat = Cat();

std::cout << "Dog: " << dog.getType() << " - ";
dog.makeSound();
dog.getIdea();

std::cout << "Cat: " << cat.getType() << " - ";
cat.makeSound();
cat.getIdea();

std::cout << "\n\n### TEST DEEPCOPY ANIMALS ###\n\n" << std::endl;

{
  Dog tmpDog = dog;
  std::cout << "TEMP Dog: " << dog.getType() << std::endl;
  tmpDog.getIdea();
}

std::cout << "Dog: " << dog.getType() << std::endl;
dog.getIdea();

return 0;
}
