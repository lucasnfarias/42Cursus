/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:32:28 by lniehues          #+#    #+#             */
/*   Updated: 2022/05/05 20:45:30 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class Intern
{

	public:

		Intern();
		Intern( Intern const & src );
		~Intern();

		Intern &		operator=( Intern const & rhs );

    AForm* makeForm(std::string formName, std::string formTarget);

	private:
    static std::string _formNamesList[3];
    AForm*  _createShrubberyCreationForm(std::string target);
    AForm*  _createRobotomyRequestForm(std::string target);
    AForm*  _createPresidentialPardonForm(std::string target);
};

std::ostream &			operator<<( std::ostream & o, Intern const & i );

#endif /* ********************************************************** INTERN_H */
