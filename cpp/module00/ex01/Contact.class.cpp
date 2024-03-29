/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:15:36 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/06 18:16:06 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.class.hpp"

Contact::Contact( void ) {
	std::cout << "Creating empty contact..." << std::endl;
	return;
};

Contact::Contact(
	std::string firstName,
	std::string lastName,
	std::string nickname,
	std::string phoneNumber,
	std::string darkestSecret
) :
	_firstName(firstName),
	_lastName(lastName),
	_nickname(nickname),
	_phoneNumber(phoneNumber),
	_darkestSecret(darkestSecret)
{
	std::cout << std::endl;
	std::cout << "# Contact created and filled! #" << std::endl;
	std::cout << "First Name: " << this->_firstName << std::endl;
	std::cout << "Last Name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone Number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->_darkestSecret << std::endl;
	std::cout << std::endl;
};

std::string Contact::getFirstName() const {
	return this->_firstName;
};

void Contact::setFirstName(std::string value) {
	this->_firstName = value;
	return;
};

std::string Contact::getLastName() const {
	return this->_lastName;
};

void Contact::setLastName(std::string value) {
	this->_lastName = value;
	return;
};

std::string Contact::getNickname() const {
	return this->_nickname;
};

void Contact::setNickname(std::string value) {
	this->_nickname = value;
	return;
};

std::string Contact::getPhoneNumber() const {
	return this->_phoneNumber;
};

void Contact::setPhoneNumber(std::string value) {
	this->_phoneNumber = value;
	return;
};

std::string Contact::getDarkestSecret() const {
	return this->_darkestSecret;
};

void Contact::setDarkestSecret(std::string value) {
	this->_darkestSecret = value;
	return;
};


Contact::~Contact( void ) {
	if (this->_firstName == "")
		std::cout << "Empty Contact Gone!" << std::endl;
	else
		std::cout << "Contact " + this->_firstName + " Gone!" << std::endl;
	return;
};
