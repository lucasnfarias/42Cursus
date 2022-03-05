/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:14:48 by lniehues          #+#    #+#             */
/*   Updated: 2022/03/05 16:29:14 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H
# include <iostream>
# include <string>

class Contact {
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;

public:
	Contact( void );
	~Contact( void );

	void fill(
		std::string first_name,
		std::string last_name,
		std::string nickname,
		std::string phone_number,
		std::string darkest_secret
	);

	std::string getFirstName() const;
	void setFirstName(std::string value);
	std::string getLastName() const;
	void setLastName(std::string value);
	std::string getNickname() const;
	void setNickname(std::string value);
	std::string getPhoneNumber() const;
	void setPhoneNumber(std::string value);
	std::string getDarkestSecret() const;
	void setDarkestSecret(std::string value);
};

#endif
