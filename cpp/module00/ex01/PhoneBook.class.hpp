/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:14:48 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/04 23:16:59 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H
# include <iostream>
# include <string>
# include "Contact.class.hpp"

class PhoneBook {
private:
	Contact	contacts[8];
	int 	index = 0;

public:
	PhoneBook( void );
	~PhoneBook( void );

	void	add_contact( void );
	void	search_contacts( void );
	void	exit( void );
};

#endif
