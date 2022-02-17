/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:25:54 by lniehues          #+#    #+#             */
/*   Updated: 2022/02/16 21:10:58 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook( void ) {
	std::cout << "Creating Phone Book..." << std::endl;
	return;
};

void PhoneBook::add_contact( void ) {
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	std::cout << std::endl;
	std::cout << "Type first name: ";
	std::cin >> first_name;

	std::cout << "Type last name: ";
	std::cin >> last_name;

	std::cout << "Type nickname: ";
	std::cin >> nickname;

	std::cout << "Type phone number: ";
	std::cin >> phone_number;

	std::cout << "Type darkest secret: ";
	std::cin >> darkest_secret;
	std::cout << std::endl;

	Contact	new_contact;

	new_contact.fill(
		first_name,
		last_name,
		nickname,
		phone_number,
		darkest_secret
	);

	this->contacts[this->index] = new_contact;
	(this->index)++;

	if (this->index == 8) this->index = 0;

	return;
};

std::string formattedStringGenerator(std::string str) {
	if (str.length() <= 10) return (str);
	return (str.substr(0, 9) + ".");
};

void PhoneBook::search_contacts( void ) {
	int i = 0;
	std::cout << "SEARCHING..." << std::endl;
	if (this->contacts[0]._first_name == "") {
		std::cout << "\n########################\n";
		std::cout << "# NO CONTACTS FOUND :( #";
		std::cout << "\n########################\n";
		return;
	}

	std::cout << std::setw(10) << "index";
	std::cout << "|";
	std::cout << std::setw(10) << "first name";
	std::cout << "|";
	std::cout << std::setw(10) << "last name";
	std::cout << "|";
	std::cout << std::setw(10) << "nickname";
	std::cout << std::endl;

	while (i < 8) {
		if (this->contacts[i]._first_name != "") {
			std::cout << std::setw(10) << i;
			std::cout << "|";
			std::cout << std::setw(10) << formattedStringGenerator(this->contacts[i]._first_name);
			std::cout << "|";
			std::cout << std::setw(10) << formattedStringGenerator(this->contacts[i]._last_name);
			std::cout << "|";
			std::cout << std::setw(10) << formattedStringGenerator(this->contacts[i]._nickname);
			std::cout << std::endl;
		}
		i++;
	}

	return;
};

void PhoneBook::exit( void ) {
	std::cout << "BYE BYE :)" << std::endl;
	return;
};

PhoneBook::~PhoneBook( void ) {
	std::cout << "Burning Phone Book..." << std::endl;
	return;
};
