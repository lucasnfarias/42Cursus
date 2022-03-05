/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:14:48 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/05 16:42:15 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

int main( void ) {
	PhoneBook	clumsy_phonebook;
	std::string	input;

	std::cout << "\n##########################################################\n";
	std::cout << "\n  WELCOME TO THE GREATEST PHONE BOOK YOU HAVE EVER SEEN!\n";
	std::cout << "\n##########################################################\n";

	while (1) {
		std::cout << "\nType one of the below commands:" << std::endl;
		std::cout << "1) ADD" << std::endl;
		std::cout << "2) SEARCH" << std::endl;
		std::cout << "3) EXIT" << std::endl;
		std::cout << "## Any other command will be discarded ##" << std::endl;
		std::cout << std::endl << "# Input: ";
		std::cin >> input;
		std::cout << std::endl;

		if (input == "ADD") clumsy_phonebook.add_contact();
		else if (input == "SEARCH") clumsy_phonebook.search_contacts();
		else if (input == "EXIT") {
			clumsy_phonebook.exit();
			break;
		}
		else std::cout << "\n# Come on bro that's not a real command :/ #\n" << std::endl;
	}

	return (0);
}
