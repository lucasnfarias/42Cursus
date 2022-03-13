/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:25:54 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/12 14:01:39 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{
    std::cout << "Creating Phone Book..." << std::endl;
    return;
};

int PhoneBook::_index = 0;

void PhoneBook::add_contact(void)
{
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    // CHECK IF THE INPUT IS NOT EMPTY IF IT IS MESSAGE AND REPROMPT THE QUESTION

    std::getline(std::cin, firstName);

    std::cout << "Type first name: ";
    std::getline(std::cin, firstName);

    std::cout << "Type last name: ";
    std::getline(std::cin, lastName);

    std::cout << "Type nickname: ";
    std::getline(std::cin, nickname);

    std::cout << "Type phone number: ";
    std::getline(std::cin, phoneNumber);

    std::cout << "Type darkest secret: ";
    std::getline(std::cin, darkestSecret);
    std::cout << std::endl;

    if (
        firstName == "" ||
        lastName == "" ||
        nickname == "" ||
        phoneNumber == "" ||
        darkestSecret == "")
    {
        std::cout << "Sorry, some fields are empty so we can't add it to the list." << std::endl;
        std::cout << "Try again and do not forget to fill all the fields requested ;)" << std::endl;
        return;
    }

    Contact new_contact(
        firstName,
        lastName,
        nickname,
        phoneNumber,
        darkestSecret);

    PhoneBook::_contacts[PhoneBook::_index] = new_contact;
    (PhoneBook::_index)++;

    if (PhoneBook::_index == 8)
        PhoneBook::_index = 0;

    return;
};

std::string formattedStringGenerator(std::string str)
{
    if (str.length() <= 10)
        return (str);
    return (str.substr(0, 9) + ".");
};

void PhoneBook::search_contacts(void)
{
    int i = 0;

    std::cout << "SEARCHING..." << std::endl;
    if (PhoneBook::_contacts[0].getFirstName() == "")
    {
        std::cout << "\n########################\n";
        std::cout << "# NO CONTACTS FOUND :( #";
        std::cout << "\n########################\n";
        return;
    }

    std::cout << std::setw(10) << "index" << "|";
    std::cout << std::setw(10) << "first name" << "|";
    std::cout << std::setw(10) << "last name" << "|";
    std::cout << std::setw(10) << "nickname" << std::endl;

    while (i < 8)
    {
        if (PhoneBook::_contacts[i].getFirstName() != "")
        {
            std::cout << std::setw(10) << i;
            std::cout << "|";
            std::cout << std::setw(10) << formattedStringGenerator(PhoneBook::_contacts[i].getFirstName());
            std::cout << "|";
            std::cout << std::setw(10) << formattedStringGenerator(PhoneBook::_contacts[i].getLastName());
            std::cout << "|";
            std::cout << std::setw(10) << formattedStringGenerator(PhoneBook::_contacts[i].getNickname());
            std::cout << std::endl;
        }
        i++;
    }

    std::cout << std::endl << "Type the contact's index you want to see the details: ";
    std::cin >> i;

    if (i < 8 && PhoneBook::_contacts[i].getFirstName() != "")
    {
        std::cout << "\n########################\n\n";
        std::cout << "First Name: " << PhoneBook::_contacts[i].getFirstName() << std::endl;
        std::cout << "Last Name: " << PhoneBook::_contacts[i].getLastName() << std::endl;
        std::cout << "Nickname: " << PhoneBook::_contacts[i].getNickname() << std::endl;
        std::cout << "Phone Number: " << PhoneBook::_contacts[i].getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << PhoneBook::_contacts[i].getDarkestSecret() << std::endl;
        std::cout << "\n########################\n";
    }
    else {
        std::cout << "\n########################\n\n";
        std::cout << "Sorry :( the index you select is out of range or it's an empty contact!" << std::endl;
        std::cout << "Next time try selecting an index showed in the table above." << std::endl;
        std::cout << "\n########################\n";
    }

    return;
};

void PhoneBook::exit(void)
{
    std::cout << "Exiting the Phone Book..." << std::endl;
    std::cout << "BYE BYE :)" << std::endl;
    return;
};

PhoneBook::~PhoneBook(void)
{
    std::cout << "Burning Phone Book..." << std::endl;
    return;
};
