/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:15:36 by lniehues          #+#    #+#             */
/*   Updated: 2022/02/13 21:20:18 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.class.hpp"

Contact::Contact( void ) {
	std::cout << "Creating Contact..." << std::endl;
	return;
};

void Contact::fill(
	std::string first_name,
	std::string last_name,
	std::string nickname,
	std::string phone_number,
	std::string darkest_secret
)
{
	this->_first_name = first_name;
	this->_last_name = last_name;
	this->_nickname = nickname;
	this->_phone_number = phone_number;
	this->_darkest_secret = darkest_secret;

	std::cout << "Contact Created!" << std::endl;
	std::cout << "First Name: " << this->_first_name << std::endl;
	std::cout << "Last Name: " << this->_last_name << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone Number: " << this->_phone_number << std::endl;
	std::cout << "Darkest Secret: " << this->_darkest_secret << std::endl;
};

Contact::~Contact( void ) {
	std::cout << "Contact " + this->_first_name + " Gone!" << std::endl;
	return;
};
