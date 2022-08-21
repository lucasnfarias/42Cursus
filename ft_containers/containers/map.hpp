/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:27:34 by lniehues          #+#    #+#             */
/*   Updated: 2022/08/18 20:58:54 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_HPP
# define FT_MAP_HPP
# include <iostream>

# include <string>
# include <exception>
# include "../utils/type_traits.hpp"
# include "../iterators/random_access_iterator.hpp"
# include "../iterators/reverse_iterator.hpp"
# include "../utils/algorithm.hpp"
# include "../utils/pair.hpp"

namespace ft {
template <
  class Key,                                            // map::key_type
  class T,                                              // map::mapped_type
  class Compare = std::less<Key>,                       // map::key_compare
  class Alloc = std::allocator<ft::pair<const Key,T>>   // map::allocator_type
> class map
{
public:
  typedef Key                                         key_type;
  typedef T                                           mapped_type;
  typedef ft::pair<const Key, T>                      value_type;
  typedef Compare                                     key_compare;
  typedef Alloc                                       allocator_type;

  typedef typename allocator_type::reference          reference;
  typedef typename allocator_type::const_reference    const_reference;
  typedef typename allocator_type::pointer            pointer;
  typedef typename allocator_type::const_pointer      const_pointer;

  // this needs to implement the map iterator with the red black tree

  // typedef typename tree_type::iterator                iterator;
  // typedef typename tree_type::const_iterator          const_iterator;
  // typedef typename tree_type::reverse_iterator        reverse_iterator;
  // typedef typename tree_type::const_reverse_iterator  const_reverse_iterator;
  // typedef typename iterator_traits<iterator>::difference_type difference_type;
  // typedef typename tree_type::size_type               size_type;

  class value_compare
  : public std::binary_function<value_type, value_type, bool>
  {
    friend class map;

    protected:
      Compare comp;

      value_compare(Compare _c) : comp(_c) {}

    public:
      bool operator()(const value_type& __x, const value_type& __y) const
      { return comp(__x.first, __y.first); }
  };

};

}

#endif
