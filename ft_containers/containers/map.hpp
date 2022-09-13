/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:27:34 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/13 16:59:42 by lniehues         ###   ########.fr       */
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
# include "../red_black_tree/tree.hpp"

namespace ft {
template <
  class Key,                                            // map::key_type
  class T,                                              // map::mapped_type
  class Compare = std::less<Key>,                       // map::key_compare
  class Alloc = std::allocator<ft::pair<const Key,T> >   // map::allocator_type
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

private:
  typedef RBTree<Key, T, _Select1st<value_type>, Compare, Alloc> _tree_type;

public:
  typedef typename _tree_type::iterator iterator;
  typedef typename _tree_type::const_iterator const_iterator;
  typedef typename _tree_type::reverse_iterator reverse_iterator;
  typedef typename _tree_type::const_reverse_iterator const_reverse_iterator;
  typedef typename _tree_type::size_type size_type;
  typedef typename iterator_traits<iterator>::difference_type difference_type;

private:
  _tree_type _tree;

public:
  explicit map(
    const key_compare &comp = key_compare(),
    const allocator_type &alloc = allocator_type()
  )
    : _tree(comp, alloc) {};

  template <class InputIterator>
  map(
    InputIterator first,
    InputIterator last,
    const key_compare &comp = key_compare(),
    const allocator_type &alloc = allocator_type()
  )
    : _tree(comp, alloc)
  {
    _tree.insertUnique(first, last);
  };

  map(const map &x) : _tree(x._tree) {}

  ~map() {}

  map &operator=(const map &x)
  {
    if (this != &x)
      _tree = x._tree;

    return *this;
  }

  // ITERATORS

  iterator begin() { return _tree.begin(); }

  const_iterator begin() const { return _tree.begin(); }

  iterator end() { return _tree.end(); }

  const_iterator end() const { return _tree.end(); }

  reverse_iterator rbegin() { return _tree.rbegin(); }

  const_reverse_iterator rbegin() const { return _tree.rbegin(); }

  reverse_iterator rend() { return _tree.rend(); }

  const_reverse_iterator rend() const { return _tree.rend(); }

  // CAPACITY

  bool empty() const { return _tree.empty(); }

  size_type size() const { return _tree.size(); }

  size_type max_size() const { return _tree.max_size(); }


  // ELEMENT ACCESS

  mapped_type &operator[](const key_type &k)
  {
    return (*((insert(ft::make_pair(k, mapped_type()))).first)).second;
  }

  // MODIFIERS

  ft::pair<iterator, bool> insert(const value_type &val) {
    return _tree.insertUnique(val);
  }

  iterator insert(iterator position, const value_type &val)
  {
    return _tree.insertUnique(position, val);
  }

  template <class InputIterator>
  void insert(InputIterator first, InputIterator last)
  {
    _tree.insertUnique(first, last);
  }

  void erase(iterator pos) { return _tree.erase(pos); }

  size_type erase(const key_type &key) { return _tree.erase(key); }

  void erase(iterator first, iterator last) { return _tree.erase(first, last); }

  void swap(map &x) { _tree.swap(x._tree); }

  void clear() { _tree.clear(); }

  // OBSERVERS

  key_compare key_comp() const { return _tree.key_comp(); }

  value_compare value_comp() const { return value_compare(key_comp); }

  // OPERATIONS

  iterator find(const key_type &key) { return _tree.find(key); }

  const_iterator find(const key_type &key) const { return _tree.find(key); }

  size_type count(const key_type &key) const { return _tree.count(key); }

  iterator lower_bound(const key_type &k) { return _tree.lower_bound(k); }

  const_iterator lower_bound(const key_type &k) const { return _tree.lower_bound(k); }

  iterator upper_bound(const key_type &k) { return _tree.upper_bound(k); }

  const_iterator upper_bound(const key_type &k) const { return _tree.upper_bound(k); }

  ft::pair<iterator, iterator> equal_range(const key_type &k)
  {
    return _tree.equal_range(k);
  }

  ft::pair<const_iterator, const_iterator>
  equal_range(const key_type &k) const
  {
    return _tree.equal_range(k);
  }

  // ALLOCATOR

  allocator_type get_allocator() const { return _tree.get_allocator(); }
};

template <class Key, class T, class Compare, class Alloc>
bool operator==(
  const map<Key, T, Compare, Alloc> &lhs,
  const map<Key, T, Compare, Alloc> &rhs
)
{
  return lhs.size() == rhs.size() &&
       ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <class Key, class T, class Compare, class Alloc>
bool operator!=(const map<Key, T, Compare, Alloc> &lhs,
                const map<Key, T, Compare, Alloc> &rhs
)
{ return !(lhs == rhs); }

template <class Key, class T, class Compare, class Alloc>
bool operator<(const map<Key, T, Compare, Alloc> &lhs,
               const map<Key, T, Compare, Alloc> &rhs
)
{
  return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                   rhs.end());
}

template <class Key, class T, class Compare, class Alloc>
bool operator>(const map<Key, T, Compare, Alloc> &lhs,
               const map<Key, T, Compare, Alloc> &rhs
)
{ return rhs < lhs; }

template <class Key, class T, class Compare, class Alloc>
bool operator<=(const map<Key, T, Compare, Alloc> &lhs,
                const map<Key, T, Compare, Alloc> &rhs
)
{ return !(rhs < lhs); }

template <class Key, class T, class Compare, class Alloc>
bool operator>=(const map<Key, T, Compare, Alloc> &lhs,
                const map<Key, T, Compare, Alloc> &rhs
)
{ return !(lhs < rhs); }

template <class Key, class T, class Compare, class Alloc>
void swap(
  map<Key, T, Compare, Alloc> &lhs,
  map<Key, T, Compare, Alloc> &rhs
)
{ lhs.swap(rhs); }

}

#endif
