/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 20:40:08 by lniehues          #+#    #+#             */
/*   Updated: 2022/06/13 20:41:49 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>
# include <deque>

template <typename T> // maybe check if can pass container type default stack container is deque
class MutantStack : public std::stack<T>
{

	public:

		MutantStack() {};
		MutantStack( MutantStack const & src ) { (void)src; };
		~MutantStack() {};

		MutantStack &		operator=( MutantStack const & rhs ) { (void)rhs; };

	private:

};

template <typename T>
std::ostream &			operator<<( std::ostream & o, MutantStack<T> const & i );

#endif /* ***************************************************** MUTANTSTACK_H */
