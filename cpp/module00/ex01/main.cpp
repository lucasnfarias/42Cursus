/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:14:48 by lniehues          #+#    #+#             */
/*   Updated: 2022/01/29 21:37:40 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"
using namespace std;
/* using namespace std; and create namespace Megaphone with functions */

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

void print_str_upperized(char *str) {
	int len = ft_strlen(str);
	for (int i = 0; i < len; i++) {
		cout << (char)ft_toupper(str[i]);
	}
	return;
}

int main(int argc, char **argv) {
	if (argc == 1) {
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
	}
	else {
		for (int i = 1; i < argc; i++) {
			print_str_upperized(argv[i]);
		}
		cout << endl;
	}

	return (0);
}
