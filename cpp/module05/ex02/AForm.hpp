/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:48:03 by lniehues          #+#    #+#             */
/*   Updated: 2022/05/02 21:48:47 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{

	public:

    AForm(std::string name, int signGrade, int executionGrade);
		AForm( AForm const & src );
		virtual ~AForm();

		AForm &		operator=( AForm const & rhs );

    const std::string getName() const;
    bool  getIsSigned() const;
    int getSignGrade() const;
    int getExecutionGrade() const;
    std::string getTarget() const;
    void setTarget(std::string & target);

    void  beSigned(Bureaucrat const & bureaucrat);
    virtual bool execute(Bureaucrat const & executor) const = 0;

  protected:
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
    class NoSignatureException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
          return "Error: form_is_not_signed";
				}
		};

	private:
    const std::string _name;
    bool  _isSigned;
    const int  _signGrade;
    const int  _executionGrade;
    std::string _target;
    static const int  _highestGrade;
    static const int  _lowestGrade;
    void  _gradeChecker();
		AForm();
};

std::ostream &			operator<<( std::ostream & o, AForm const & i );

#endif /* ************************************************************ FORM_H */
