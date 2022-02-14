/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:25:54 by lniehues          #+#    #+#             */
/*   Updated: 2022/02/13 21:30:57 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
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

	std::cout << "Type first name: " << std::endl;
	std::cin >> first_name;

	std::cout << "Type last name: " << std::endl;
	std::cin >> last_name;

	std::cout << "Type nickname: " << std::endl;
	std::cin >> nickname;

	std::cout << "Type phone number: " << std::endl;
	std::cin >> phone_number;

	std::cout << "Type darkest secret: " << std::endl;
	std::cin >> darkest_secret;

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

void PhoneBook::search_contacts( void ) {
	int i = 0;
	std::cout << "SEARCHING..." << std::endl;
	while (i < 8) {
		if (this->contacts[i]._first_name != "") {
			std::cout << "#" << i << std::endl;
			std::cout << "First Name: " << this->contacts[i]._first_name << std::endl;
			std::cout << "Last Name: " << this->contacts[i]._last_name << std::endl;
			std::cout << "Nickname: " << this->contacts[i]._nickname << std::endl;
			std::cout << "Phone Number: " << this->contacts[i]._phone_number << std::endl;
			std::cout << "Darkest Secret: " << this->contacts[i]._darkest_secret << std::endl;
			std::cout << "--------------------" << std::endl;
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
