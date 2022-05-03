/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:48:03 by lniehues          #+#    #+#             */
/*   Updated: 2022/05/02 21:48:47 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

	public:

		Form();
    Form(std::string name, int signGrade, int executionGrade);
		Form( Form const & src );
		~Form();

		Form &		operator=( Form const & rhs );

    class GradeTooHighException : public std::exception {
      public:
        virtual const char* what() const throw()
        {
          return "Error: grade_too_high";
        }
    };
    class GradeTooLowException : public std::exception {
      public:
        virtual const char* what() const throw()
        {
          return "Error: grade_too_low";
        }
    };

    const std::string getName() const;
    bool  getIsSigned() const;
    int getSignGrade() const;
    int getExecutionGrade() const;

    void  beSigned(Bureaucrat & bureaucrat);

	private:
    const std::string _name;
    bool  _isSigned;
    const int  _signGrade;
    const int  _executionGrade;
    static const int  _highestGrade;
    static const int  _lowestGrade;
    void  _gradeChecker();
};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */
