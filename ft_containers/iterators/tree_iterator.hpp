/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:38:19 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/23 22:31:35 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

# include "../utils/type_traits.hpp"
# include "../iterators/iterators_traits.hpp"
# include "../red_black_tree/node.hpp"

namespace ft {

template <class T>
class TreeIterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
{

public:
  typedef T value_type;
  typedef T *pointer;
  typedef T &reference;

  typedef ft::bidirectional_iterator_tag iterator_category;
  typedef ptrdiff_t difference_type;

  typedef typename ft::Node<T>::node_pointer node_pointer;

  node_pointer  _node;

  node_pointer _leaf;

public:
  TreeIterator() : _node(), _leaf() {}

  TreeIterator(node_pointer node, node_pointer leaf) : _node(node), _leaf(leaf) {}

  TreeIterator(const TreeIterator<T> &it) : _node(it._node), _leaf(it._leaf) {}

  ~TreeIterator() {}

  TreeIterator<T> &operator=(const TreeIterator<T> &it)
  {
    if (this != &it) {
      _node = it._node;
      _leaf = it._leaf;
    }
    return *this;
  }


  reference operator*() const { return *_node->content; }

  pointer operator->() const { return &(operator*()); }

  node_pointer _minimum(node_pointer node)
  {
    while (node->leftChild != _leaf)
      node = node->leftChild;
    return node;
  }

  node_pointer _maximum(node_pointer node)
  {
    while (node->rightChild != _leaf)
      node = node->rightChild;
    return node;
  }

  node_pointer _successor(node_pointer x)
  {
    if (x->rightChild != _leaf)
      return _minimum(x->rightChild);

    node_pointer y = x->parent;
    while (y != _leaf && x == y->rightChild) {
      x = y;
      y = y->parent;
    }

    return y;
  }

  node_pointer _predecessor(node_pointer x) {
    if (x == _leaf)
      return x->parent;

    if (x->leftChild != _leaf)
      return _maximum(x->leftChild);

    node_pointer y = x->parent;
    while (y != _leaf && x == y->leftChild) {
      x = y;
      y = y->parent;
    }

    return y;
  }

  TreeIterator<T> &operator++()
  {
    _node = _successor(_node);
    return *this;
  }

  TreeIterator<T> operator++(int)
  {
    TreeIterator<T> temp = *this;
    ++*this;
    return temp;
  }

  TreeIterator<T> &operator--()
  {
    _node = _predecessor(_node);
    return *this;
  }

  TreeIterator<T> operator--(int)
  {
    TreeIterator<T> temp = *this;
    --*this;
    return temp;
  }

  bool operator==(const TreeIterator<T> &it) const { return _node == it._node; }

  bool operator!=(const TreeIterator<T> &it) const { return _node != it._node; }
};

template <class T>
class ConstTreeIterator
{

public:
  typedef T value_type;
  typedef T *pointer;
  typedef T &reference;

  typedef ft::bidirectional_iterator_tag iterator_category;
  typedef ptrdiff_t difference_type;

  typedef typename ft::Node<T>::node_pointer node_pointer;

  node_pointer  _node;

  node_pointer _leaf;

public:
  ConstTreeIterator() : _node(), _leaf() {}

  ConstTreeIterator(node_pointer node, node_pointer leaf) : _node(node), _leaf(leaf) {}

  ConstTreeIterator(const ConstTreeIterator<T> &it) : _node(it._node), _leaf(it._leaf) {}

  ConstTreeIterator(const TreeIterator<T> &it) : _node(it._node), _leaf(it._leaf) {}

  ~ConstTreeIterator() {}

  ConstTreeIterator<T> &operator=(const ConstTreeIterator<T> &it)
  {
    if (this != &it) {
      _node = it._node;
      _leaf = it._leaf;
    }
    return *this;
  }

  reference operator*() const { return *_node->content; }

  pointer operator->() const { return &(operator*()); }

  node_pointer _minimum(node_pointer node)
  {
    while (node->leftChild != _leaf)
      node = node->leftChild;
    return node;
  }

  node_pointer _maximum(node_pointer node)
  {
    while (node->rightChild != _leaf)
      node = node->rightChild;
    return node;
  }

  node_pointer _successor(node_pointer x)
  {
    if (x->rightChild != _leaf)
      return _minimum(x->rightChild);

    node_pointer y = x->parent;
    while (y != _leaf && x == y->rightChild) {
      x = y;
      y = y->parent;
    }

    return y;
  }

  node_pointer _predecessor(node_pointer x) {
    if (x == _leaf)
      return x->parent;

    if (x->leftChild != _leaf)
      return _maximum(x->leftChild);

    node_pointer y = x->parent;
    while (y != _leaf && x == y->leftChild) {
      x = y;
      y = y->parent;
    }

    return y;
  }

  ConstTreeIterator<T> &operator++()
  {
    _node = _successor(_node);
    return *this;
  }

  ConstTreeIterator<T> operator++(int)
  {
    ConstTreeIterator<T> temp = *this;
    ++*this;
    return temp;
  }

  ConstTreeIterator<T> &operator--()
  {
    _node = _predecessor(_node);
    return *this;
  }

  ConstTreeIterator<T> operator--(int)
  {
    ConstTreeIterator<T> temp = *this;
    --*this;
    return temp;
  }

  bool operator==(const ConstTreeIterator<T> &it) const { return _node == it._node; }

  bool operator!=(const ConstTreeIterator<T> &it) const { return _node != it._node; }
};

template <class T>
inline bool operator==(
  const TreeIterator<T> &it1,
  const ConstTreeIterator<T> &it2
)
{
  return it1._node == it2._node;
}

template <class T>
inline bool operator!=(
  const TreeIterator<T> &it1,
  const ConstTreeIterator<T> &it2
)
{
  return !(it1 == it2);
}

}

#endif
