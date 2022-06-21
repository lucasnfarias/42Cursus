/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:07:01 by lniehues          #+#    #+#             */
/*   Updated: 2022/05/05 19:07:01 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
  :
  AForm("ShrubberyCreationForm", 145, 137)
{
  setTarget(target);
  std::cout << *this << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src )
  :
  AForm(src)
{}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm() {}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )
{
  o
  << "---" << std::endl
  << i.getName()
  << " Form"
  << std::endl
  << "# Sign grade: "
  << i.getSignGrade()
  << std::endl
  << "# Execution grade: "
  << i.getExecutionGrade()
  << std::endl
  << "# Signed: "
  << (i.getIsSigned() ? "YES" : "NO")
  << std::endl
  << "# Target: "
  << i.getTarget()
  << std::endl << "---" << std::endl
  << std::endl;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

bool ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
  if (AForm::execute(executor))
  {
    _createFile();
    return true;
  }
  return false;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void		ShrubberyCreationForm::_createFile() const
{
	std::string line;
	std::string filename = getTarget() + "_shrubbery";
	std::ofstream outputFile(filename.c_str());
	std::ifstream inputFile("awesome_tree.txt");

	if(inputFile && outputFile)
	{
		while(getline(inputFile, line))
			outputFile << line << std::endl;
		std::cout << filename << " has been created and it's filled with an awesome ASCII tree!" << std::endl;
	}
	else
		std::cerr << "Error creating file" << std::endl;
	outputFile.close();
	inputFile.close();
}

/* ************************************************************************** */
