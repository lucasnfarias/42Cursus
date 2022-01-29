/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class .hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:14:48 by lniehues          #+#    #+#             */
/*   Updated: 2022/01/29 21:41:26 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H
# include <iostream>
# include "Contact.class.hpp"

class PhoneBook {

public:
	int	contacts[8];
	
	PhoneBook( void );
	~PhoneBook( void );

	void	add_contact(
		char *first_name,
		char *last_name,
		char *nickname,
		char *phone_number,
		char *darkest_secret);
	void	search_contacts( void );
	void	exit( void );
};

PhoneBook::add_contact(
	char *first_name,
	char *last_name,
	char *nickname,
	char *phone_number,
	char *darkest_secret
) {
	Contact	new_contact;
	
	contact.
}

#endif
