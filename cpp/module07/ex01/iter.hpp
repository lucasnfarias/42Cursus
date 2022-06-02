/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 01:46:54 by coder             #+#    #+#             */
/*   Updated: 2022/06/02 15:30:52 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include "Example.hpp"

template<typename T>
void	iter(T *arrayAddress, size_t length, void (function)(T &arrayItem))
{
	for (size_t i = 0; i < length; i++)
		function(arrayAddress[i]);
}

template<typename T>
void	iter(T const *arrayAddress, size_t length, void (function)(T const &arrayItem))
{
	for (size_t i = 0; i < length; i++)
		function(arrayAddress[i]);
}

template<typename T>
void	minusOne(T &item)
{
	item -= 1.0;
}

template<typename T>
void	triple(T &item)
{
	item *= 3;
}

template<typename T>
void	myPrint(T &item)
{
	std::cout << "item: " << item << std::endl;
}

void	add42ToString(std::string	&item)
{
	item.append(" - 42");
}

void	plusTwoToGrade(Example &item)
{
	item.setGrade(item.getGrade() + 2);
}

void enterToContinue()
{
  std::cout << "\nPress enter to continue...\n";
  std::cin.ignore();
}

#endif
