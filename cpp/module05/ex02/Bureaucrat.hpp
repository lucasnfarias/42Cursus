/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:06:32 by lniehues          #+#    #+#             */
/*   Updated: 2022/05/05 19:06:33 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{

	public:

		Bureaucrat();
    Bureaucrat( std::string name, int grade );
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );

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
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    void  signForm(AForm & form);
    void  executeForm(AForm const & form);

	private:
    void  _gradeChecker();
    const std::string _name;
    int  _grade;
    static const int  _highestGrade;
    static const int  _lowestGrade;
};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */
