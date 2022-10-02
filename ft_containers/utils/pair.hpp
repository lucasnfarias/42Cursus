/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:30:09 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/10 17:08:10 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{

template <class T1, class T2> struct pair
{
    typedef T1 first_type;
    typedef T2 second_type;

    first_type first;
    second_type second;

    pair(): first(), second() {}

    template <class U, class V>
    pair(const pair<U, V> &pr) : first(pr.first), second(pr.second) {}

    pair(const first_type& a, const second_type& b) : first(a), second(b) {}

    pair& operator=(const pair& pr)
    {
      if (this != &pr)
      {
        first = pr.first;
        second = pr.second;
      }
      return *this;
    }
};

// Pair non-member operators overload
template <class T1, class T2>
bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
{
  return lhs.first == rhs.first && lhs.second == rhs.second;
}

template <class T1, class T2>
bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
{
  return !(lhs == rhs);
}

template <class T1, class T2>
bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
{
  return lhs.first < rhs.first ||
         (!(rhs.first < lhs.first) && lhs.second < rhs.second);
}

template <class T1, class T2>
bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
{
  return !(rhs < lhs);
}

template <class T1, class T2>
bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
{
  return rhs < lhs;
}

template <class T1, class T2>
bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
{
  return !(lhs < rhs);
}

// make_pair auxiliary function
template <class T1, class T2>
pair<T1, T2> make_pair(T1 x, T2 y)
{
  return (pair<T1, T2>(x, y));
}

// stl_function.h - used on red black tree and map

/**
 * @brief Base class for standard unary function objects.
 * @tparam Arg The argument type.
 * @tparam Result The result type.
 */
template <typename Arg, typename Result>
struct unary_function
{
  typedef Arg argument_type;
  typedef Result result_type;
};

template <class Pair>
struct _Select1st : public unary_function<Pair, typename Pair::first_type>
{
  typename Pair::first_type &operator()(Pair &x) const
  {
    return x.first;
  }

  const typename Pair::first_type &operator()(const Pair &x) const
  {
    return x.first;
  }
};

}


#endif
