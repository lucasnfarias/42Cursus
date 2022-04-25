/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:05:39 by lniehues          #+#    #+#             */
/*   Updated: 2022/04/25 16:57:47 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* unicorn = new Animal();
const Animal* dog = new Dog();
const Animal* cat = new Cat();

std::cout << "# TYPES:" << std::endl;
std::cout << dog->getType() << std::endl;
std::cout << cat->getType() << std::endl;
std::cout << unicorn->getType() << std::endl;

std::cout << "# SOUNDS:" << std::endl;
cat->makeSound();
dog->makeSound();
unicorn->makeSound();

delete cat;
delete dog;
delete unicorn;

std::cout << std::endl << "** TEST WRONG **" << std::endl;

const WrongAnimal* wrongUnicorn = new WrongAnimal();
const WrongAnimal* wrongCat = new WrongCat();

std::cout << "# TYPES:" << std::endl;
std::cout << wrongCat->getType() << std::endl;
std::cout << wrongUnicorn->getType() << std::endl;

std::cout << "# SOUNDS:" << std::endl;
wrongCat->makeSound();
wrongUnicorn->makeSound();

delete wrongCat;
delete wrongUnicorn;

return 0;
}
