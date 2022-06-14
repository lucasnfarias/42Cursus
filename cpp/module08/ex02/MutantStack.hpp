/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 20:40:08 by lniehues          #+#    #+#             */
/*   Updated: 2022/06/14 20:11:39 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{

public:
  MutantStack(){};
  MutantStack(MutantStack const &src) : std::stack<T, Container>(src) { };
  ~MutantStack(){};

  MutantStack &operator=(MutantStack const &rhs)
  {
    if (this != &rhs)
			std::stack<T, Container>::operator=(rhs);
    return *this;
  };

  typedef typename Container::iterator iterator;
  typedef typename Container::reverse_iterator reverse_iterator;

  iterator begin() { return this->c.begin(); }
  iterator end() { return this->c.end(); }
  reverse_iterator rbegin() { return this->c.rbegin(); }
  reverse_iterator rend() { return this->c.rend(); }

private:
};

template <typename T>
std::ostream &operator<<(std::ostream &o, MutantStack<T> const &i);

#endif /* ***************************************************** MUTANTSTACK_H */
