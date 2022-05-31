/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Example.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 02:06:25 by coder             #+#    #+#             */
/*   Updated: 2022/05/31 02:18:34 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXAMPLE_HPP
# define EXAMPLE_HPP
# include <iostream>

class Example
{
public:
	Example() : _grade(42) {};
	Example(int grade) : _grade(grade) {};
	~Example() {};

	int	getGrade() const { return _grade; };
	void	setGrade(int grade) { _grade = grade; };	

private:
	int	_grade;
};

std::ostream &			operator<<( std::ostream & o, Example const & i )
{
	o << "grade: " << i.getGrade();
	return o;
}

#endif