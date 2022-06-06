/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:40:36 by lniehues          #+#    #+#             */
/*   Updated: 2022/06/06 19:51:14 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>

class ElementNotFoundException : public std::exception
{
public:
  virtual const char *what() const throw()
  {
    return ("Error: element not found.");
  }
};

template <typename T>
typename T::iterator easyfind(T &container, int element)
{
  typename T::iterator elementFound = std::find(container.begin(), container.end(), element);
  if (elementFound == container.end())
    throw ElementNotFoundException();
  return elementFound;
};

#endif
