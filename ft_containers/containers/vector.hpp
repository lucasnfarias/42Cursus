/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:27:34 by lniehues          #+#    #+#             */
/*   Updated: 2022/07/26 21:42:01 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

# include <iostream>
# include <string>
# include <exception>
# include "../utils/type_traits.hpp"
# include "../iterators/random_access_iterator.hpp"
# include "../iterators/reverse_iterator.hpp"
# include "../utils/algorithm.hpp"

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
    size_type	             _size;     // number of elements actually inside the vector
    size_type	             _capacity; // total storage capacity of the vector
    allocator_type         _alloc;    // allocator object
    value_type*            _data;     // pointer to the first element
    static const size_type _growthFactor = 2; // value which capacity will be multiplied

    void _checkRange(size_type n) const
    {
      if (n >= size())
        throw std::out_of_range("vector::_M_range_check: n >= _size");
    }

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

    void resize (size_type n, value_type val = value_type())
    {
      if (n < _size)
        for (size_type i = n; i <= _size; i++)
          _alloc.destroy(_data + i);
      else if (n > _size)
      {
        reserve(n);
        for (size_type i = _size; i < n; i++)
          _alloc.construct(_data + i, val);
      }
      _size = n;
    }

    size_type capacity() const { return _capacity; }

    bool empty() const { return _size == 0; }

    void reserve (size_type n) {
      if (n > max_size())
        throw std::length_error("ft::vector::reserve(size_type)");
      if (n > _capacity)
      {
        _capacity = n;
        pointer temp = _alloc.allocate(_capacity);

        for (size_type i = 0; i < _size; i++)
          _alloc.construct(temp + i, _data[i]);
        for (size_type i = 0; i < _size; i++)
          _alloc.destroy(_data + i);

        _alloc.deallocate(_data, _capacity);
        _data = temp;
      }
    }

    // Element Access

    reference operator[](size_type n) {  return *(begin() + n); }
    const_reference operator[](size_type n) const { return *(begin() + n); }

    reference at(size_type n) {
      _checkRange(n);
      return *(begin() + n);
    }
    const_reference at(size_type n) const {
      _checkRange(n);
      return *(begin() + n);
    }

    reference front() { return *begin(); }
    const_reference front() const { return *begin(); }

    reference back() { return *(end() - 1); }
    const_reference back() const { return *(end() - 1); }

    // Modifiers

    template <class InputIterator>
    void assign(
      InputIterator first,
      InputIterator last,
      typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = false
    )
    {
      size_type newSize = last - first;

      if (newSize > max_size())
        throw std::length_error("ft::vector:assign(InputIterator, InputIterator)");
      if (newSize > capacity)
        reserve(newSize);

      for (size_type i = 0; i < newSize; i++)
      {
        _alloc.construct(_data + i, *(first + i));
      }
      for (size_type i = newSize; i < _size; i++)
      {
        _alloc.destroy(_data + i);
      }

      _size = newSize;
    }

    void assign(size_type n, const value_type& val)
    {
      if (n > max_size())
        throw std::length_error("ft::vector:assign(size_type, const value_type&)");
      if (n > capacity)
        reserve(n);

      for (size_type i = 0; i < n; i++)
        _alloc.construct(&_data[i], val);
      for (size_type i = n; i < _size; i++)
        _alloc.destroy(&_data[i]);

      _size = n;
    }

    void push_back(const value_type& val)
    {
      if (_size == capacity())
        reserve(capacity() ? capacity() * _growthFactor : 1);

      _alloc.construct(&_data[_size], val);
      _size++;
    }

    void pop_back()
    {
      if (_size > 0) {
        _alloc.destroy(_data + _size - 1);
        _size--;
      }
    }

    iterator insert(iterator position, const value_type& val)
    {
      size_type indexInserted = position - begin();

      if (_size == capacity())
        reserve(capacity() * _growthFactor);

      for (size_type i = _size; i > indexInserted; i--)
        _alloc.construct(&_data[i], _data[i - 1]);
      _alloc.construct(&_data[indexInserted], val);
      _size++;

      return (begin() + indexInserted);
    }

    void insert(iterator position, size_type n, const value_type& val)
    {
      size_type indexInserted = position - begin();

      if (_size + n > capacity())
        reserve(capacity() * _growthFactor);

      for (size_type i = _size + n - 1; i > indexInserted; i--)
        _alloc.construct(&_data[i], _data[i - 1]);
      for (size_type i = 0; i < n; i++)
        _alloc.construct(&_data[indexInserted + i], val);
      _size += n;
    }

    template <class InputIterator>
    void insert (iterator position, InputIterator first, InputIterator last);

    // Allocator

};

    // Non-memeber functions overload

}

#endif
