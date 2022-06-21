/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 03:12:17 by coder             #+#    #+#             */
/*   Updated: 2022/06/02 15:24:25 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
  T temp;

  temp = a;
  a = b;
  b = temp;
}

template <typename T>
T const &min(T const &a, T const &b)
{
  return (a < b ? a : b);
}

template <typename T>
T const &max(T const &a, T const &b)
{
  return (a > b ? a : b);
}

class Example
{
public:
  Example(void) : _n(0) {}
  Example(int n) : _n(n) {}
  Example &operator=(Example &a)
  {
    _n = a._n;
    return *this;
  }
  bool operator==(Example const &rhs) const { return (this->_n == rhs._n); }
  bool operator!=(Example const &rhs) const { return (this->_n != rhs._n); }
  bool operator>(Example const &rhs) const { return (this->_n > rhs._n); }
  bool operator<(Example const &rhs) const { return (this->_n < rhs._n); }
  bool operator>=(Example const &rhs) const { return (this->_n >= rhs._n); }
  bool operator<=(Example const &rhs) const { return (this->_n <= rhs._n); }
  int getN() const { return _n; }

private:
  int _n;
};
std::ostream &operator<<(std::ostream &o, const Example &a)
{
  o << a.getN();
  return o;
}

void enterToContinue()
{
  std::cout << "\nPress enter to continue...\n";
  std::cin.ignore();
}

#endif
