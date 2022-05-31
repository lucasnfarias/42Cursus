/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 01:46:27 by coder             #+#    #+#             */
/*   Updated: 2022/05/31 02:23:11 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "Example.hpp"

int	main()
{
	int	intArray[4] = { 1, 3, 5, 8 };
	char	charArray[5] = { 'a', '-', 'y', 'B', '4' };
	std::string	stringArray[3] = { "Hello", "Top", "okidoki" };
	Example classArray[3];

	std::cout << "Print original arrays:\n" << std::endl;

	iter(intArray, 4, myPrint);
	std::cout << "---" << std::endl;
	iter(charArray, 5, myPrint);
	std::cout << "---" << std::endl;
	iter(stringArray, 3, myPrint);
	std::cout << "---" << std::endl;
	iter(classArray, 3, myPrint);
	
	iter(intArray, 4, triple);
	iter(charArray, 5, minusOne);
	iter(stringArray, 3, add42ToString);
	iter(classArray, 3, plusTwoToGrade);

	std::cout << "---" << std::endl;
	std::cout << "Print transformed arrays:\n" << std::endl;

	iter(intArray, 4, myPrint);
	std::cout << "---" << std::endl;
	iter(charArray, 5, myPrint);
	std::cout << "---" << std::endl;
	iter(stringArray, 3, myPrint);
	std::cout << "---" << std::endl;
	iter(classArray, 3, myPrint);
}