/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:27:34 by lniehues          #+#    #+#             */
/*   Updated: 2022/07/18 21:28:39 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

# include <iostream>
# include <string>
# include <exception>
# include "type_traits.hpp"
# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"
# include "algorithm.hpp"

namespace ft {

template < class T, class Alloc = std::allocator<T> >
class vector
{
  public:
    typedef T                                               value_type;
    typedef Alloc                                           allocator_type;
    typedef typename allocator_type::reference              reference;
    typedef typename allocator_type::const_reference        const_reference;
    typedef typename allocator_type::pointer                pointer;
    typedef typename allocator_type::const_pointer          const_pointer;
    typedef ft::random_access_iterator<value_type>          iterator;
    typedef ft::random_access_iterator<const value_type>    const_iterator;
    typedef ft::reverse_iterator<iterator>                  reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>            const_reverse_iterator;
    typedef std::ptrdiff_t                                  difference_type;
    typedef std::size_t                                     size_type;

  private:
    size_type	     _size;     // number of elements actually inside the vector
    size_type	     _capacity; // total storage capacity of the vector
    allocator_type _alloc;    // allocator object
    value_type*    _data;     // pointer to the first element

  public:
    explicit vector(const allocator_type &alloc = allocator_type())
      : _size(0), _capacity(0), _alloc(alloc), _data(NULL)
    {
      _data = _alloc.allocate(_capacity);
    };

    explicit vector(
      size_type n,
      const value_type &val = value_type(),
      const allocator_type &alloc = allocator_type()
    )
      : _size(n), _capacity(n), _alloc(alloc)
    {
      if (n > max_size())
        throw std::length_error("vector(size_type, const value_type&, const allocator_type&)");

      _data = _alloc.allocate(_capacity);

      for (size_type i = 0; i < _size; i++)
      {
        _alloc.construct(_data + i, val);
      }
    }

    template <class InputIterator>
    vector(
      InputIterator first,
      InputIterator last,
      const allocator_type &alloc = allocator_type(),
      typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 42
    )
      : _size(last - first), _capacity(last - first), _alloc(alloc), _data(_alloc.allocate(_capacity))
    {
      for (size_type i = 0; i < _size; i++)
      {
        _alloc.construct(_data + i, *(first + i));
      }
    }

    vector(const vector &src)
      : _size(src._size), _capacity(src._capacity), _alloc(Alloc(src._alloc)), _data(_alloc.allocate(_capacity))
    {

      for (size_type i = 0; i < _size; i++)
      {
        _alloc.construct(_data + i, src._data[i]);
      }
    }

    ~vector()
    {
      if (_data != NULL) {
        for (size_type i = 0; i < _size; i++) {
          _alloc.destroy(_data + i);
        }
        _alloc.deallocate(_data, _capacity);
      }
    }

    vector &operator=(const vector &rhs)
    {
      if (this != &rhs)
      {
        if (_size != rhs._size)
        {
          if (_data != NULL)
          {
            for (size_type i = 0; i < _size; i++) {
              _alloc.destroy(_data + i);
            }

            _alloc.deallocate(_data, _capacity);
          }

          _size = rhs._size;
          _capacity = rhs._capacity;
          _data = _alloc.allocate(_capacity);
        }

        for (size_type i = 0; i < _size; i++) {
          _alloc.construct(_data + i, rhs._data[i]);
        }
      }
      return *this;
    }

    // Iterators

    iterator begin() { return iterator(_data); };
    const_iterator begin() const { return const_iterator(_data); }

    iterator end() { return iterator(_data + _size); }
    const_iterator end() const { return const_iterator(_data + _size); }

    reverse_iterator rbegin() { return reverse_iterator(--end()); }
    const_reverse_iterator rbegin() const { return const_reverse_iterator(--end()); }

    reverse_iterator rend() { return reverse_iterator(--begin()); }
    const_reverse_iterator rend() const { return const_reverse_iterator(--begin()); }

    // Capacity

    size_type size() const { return _size; }

    size_type max_size() const { return _alloc.max_size(); }

    void resize (size_type n, value_type val = value_type());

    size_type capacity() const;

    bool empty() const;

    void reserve (size_type n);

    // Element Access

    // Modifiers

    // Allocator

};

    // Non-memeber functions overload

}

#endif
