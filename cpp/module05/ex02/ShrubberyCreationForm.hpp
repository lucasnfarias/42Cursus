/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:07:05 by lniehues          #+#    #+#             */
/*   Updated: 2022/05/05 19:07:05 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{

	public:

    ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		~ShrubberyCreationForm();

		ShrubberyCreationForm &		operator=( ShrubberyCreationForm const & rhs );

    virtual bool execute(Bureaucrat const & executor) const;

	private:

		ShrubberyCreationForm();
    void  _createFile() const;
};

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i );

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */
