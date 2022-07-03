/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators_traits.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:05:45 by lniehues          #+#    #+#             */
/*   Updated: 2022/07/03 18:23:16 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_TRAITS_HPP
# define ITERATORS_TRAITS_HPP

# include <cstddef> // ptrdiff_t

namespace ft {

typedef std::ptrdiff_t ptrdiff_t;

template <class Iterator>
class iterator_traits
{
  public:

    typedef typename Iterator::value_type value_type;
    typedef typename Iterator::difference_type difference_type;
    typedef typename Iterator::pointer pointer;
    typedef typename Iterator::reference reference;
    typedef typename Iterator::iterator_category iterator_category;
};

template <class T>
class iterator_traits<T*>
{
  public:
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef T &reference;
    typedef ft::random_access_iterator_tag iterator_category;
};

template <class T>
class iterator_traits<const T*>
{
  public:
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef const T *pointer;
    typedef const T &reference;
    typedef ft::random_access_iterator_tag iterator_category;
};

}

#endif
