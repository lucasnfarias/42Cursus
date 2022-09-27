/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:07:38 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/26 21:31:50 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "iterators_traits.hpp"

namespace ft
{

template <typename T>
class random_access_iterator
{
  public:

    typedef random_access_iterator<T> iterator;
    typedef std::random_access_iterator_tag iterator_category;
    typedef T value_type;
    typedef T *pointer;
    typedef T &reference;
    typedef std::ptrdiff_t difference_type;
    typedef random_access_iterator<const T> const_iterator;

  private:
    pointer _ptr;

  public:
    random_access_iterator() : _ptr(NULL) {}

    explicit random_access_iterator(pointer ptr) : _ptr(ptr) {}

    random_access_iterator(const random_access_iterator &i) : _ptr(i._ptr) {}

    ~random_access_iterator() {}

    random_access_iterator &operator=(const random_access_iterator &rhs)
    {
      if (this != &rhs)
        _ptr = rhs._ptr;
      return *this;
    }

    pointer base(void) const { return (_ptr); }

    // deference operators
    reference operator*() const { return *_ptr; }

    pointer operator->() const { return _ptr; }

    reference operator[](int n) const { return _ptr[n]; }

    // relational operators
    bool operator==(const random_access_iterator &rhs) const { return _ptr == rhs._ptr; }

    bool operator!=(const random_access_iterator &rhs) const { return _ptr != rhs._ptr; }

    bool operator>(const iterator& rhs) { return _ptr > rhs._ptr; }

    bool operator>=(const iterator& rhs) { return _ptr >= rhs._ptr; }

    bool operator<(const iterator& rhs) { return _ptr < rhs._ptr; }

    bool operator<=(const iterator& rhs) { return _ptr <= rhs._ptr; }

    //arithmetic operators
    iterator operator+(int n) { return (iterator(this->_ptr + n)); }

    iterator operator-(int n) { return (iterator(this->_ptr - n)); }

    int operator+(const iterator& rhs) { return (this->_ptr + rhs._ptr); }

    int operator-(const iterator& rhs) { return (this->_ptr - rhs._ptr); }

    iterator &operator+=(int n)
    {
      _ptr += n;
      return *this;
    }

    iterator &operator-=(int n)
    {
      _ptr -= n;
      return *this;
    }

    // in and decrementation
    iterator& operator++()
    {
      ++_ptr;
      return (*this);
    }

    iterator operator++(int)
    {
      iterator tmp(*this);
      ++_ptr;
      return (tmp);
    }

    iterator& operator--()
    {
      --_ptr;
      return (*this);
    }

    iterator operator--(int)
    {
      iterator tmp(*this);
      --_ptr;
      return (tmp);
    }

};

template<class T>
bool operator==(const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs)
{
  return lhs.base() == rhs.base();
}

template<class T>
bool operator!=(const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs)
{
  return lhs.base() != rhs.base();
}

template<class T>
bool operator<(const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs)
{
  return lhs.base() < rhs.base();
}

template<class T>
bool operator<=(const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs)
{
  return lhs.base() <= rhs.base();
}

template<class T>
bool operator>(const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs)
{
  return lhs.base() > rhs.base();
}

template<class T>
bool operator>=(const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs)
{
  return lhs.base() >= rhs.base();
}

//able comparison of reverse and const_reverse
template<class T_L, class T_R>
bool operator==(const ft::random_access_iterator<T_R>& lhs, const ft::random_access_iterator<T_L>& rhs)
{
  return lhs.base() == rhs.base();
}

template<class T_L, class T_R>
bool operator!=(const ft::random_access_iterator<T_L>& lhs, const ft::random_access_iterator<T_R>& rhs)
{
  return lhs.base() != rhs.base();
}

template<class T_L, class T_R>
bool operator<(const ft::random_access_iterator<T_L>& lhs, const ft::random_access_iterator<T_R>& rhs)
{
  return lhs.base() < rhs.base();
}

template<class T_L, class T_R>
bool operator<=(const ft::random_access_iterator<T_L>& lhs, const ft::random_access_iterator<T_R>& rhs)
{
  return lhs.base() <= rhs.base();
}

template<class T_L, class T_R>
bool operator>(const ft::random_access_iterator<T_L>& lhs, const ft::random_access_iterator<T_R>& rhs)
{
  return lhs.base() > rhs.base();
}

template<class T_L, class T_R>
bool operator>=(const ft::random_access_iterator<T_L>& lhs, const ft::random_access_iterator<T_R>& rhs)
{
  return lhs.base() >= rhs.base();
}

}

#endif
