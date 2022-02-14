/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:14:48 by lniehues          #+#    #+#             */
/*   Updated: 2022/02/13 21:29:10 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H
# include <iostream>
# include <string>
# include "Contact.class.hpp"

class PhoneBook {

public:
	Contact	contacts[8];
	int 	index = 0;

	PhoneBook( void );
	~PhoneBook( void );

	void	add_contact( void );
	void	search_contacts( void );
	void	exit( void );
};

#endif
