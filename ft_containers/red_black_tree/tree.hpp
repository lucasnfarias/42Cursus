/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:37:06 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/30 21:41:37 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# include "functional" // std::less
# include "../utils/pair.hpp"
# include "../iterators/reverse_iterator.hpp"
# include "../iterators/tree_iterator.hpp"

namespace ft {

template <
  class Key,
  class Val,
  class KeyOfValue,
  class Compare = std::less<Key>,
  class Alloc = std::allocator<ft::pair<const Key, Val> >
>
class RBTree {
public:
  typedef Key key_type;
  typedef Val mapped_type;
  typedef typename Alloc::value_type value_type;
  typedef Val *pointer;
  typedef Val &reference;
  typedef Alloc allocator_type;
  typedef Compare key_compare;
  typedef const Val *const_pointer;
  typedef const Val &const_reference;
  typedef Node<value_type, allocator_type> node_type;
  typedef node_type *node_pointer;
  typedef node_type const &node_reference;
  typedef Color node_color;
  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;
  typedef TreeIterator<value_type> iterator;
  typedef ConstTreeIterator<value_type> const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

private:
  typedef typename Alloc::template rebind< Node<value_type> >::other
    node_allocator_type;

  size_type _size;
  allocator_type _alloc;
  node_allocator_type _node_alloc;
  key_compare _compare;

  node_pointer _root;
  node_pointer _nil;

public:
  explicit RBTree(
    const key_compare &compare = key_compare(),
    const allocator_type &alloc = allocator_type()
  )
  :
    _size(0),
    _alloc(alloc),
    _node_alloc(node_allocator_type()),
    _compare(compare)
  {
    _nil = _node_alloc.allocate(1);
    _node_alloc.construct(_nil, node_type());
    _nil->parent = _nil->leftChild = _nil->rightChild = _nil;
    _root = _nil;
  }

  RBTree(const RBTree &other)
  :
    _size(other._size),
    _alloc(allocator_type(other._alloc)),
    _node_alloc(node_allocator_type(other._node_alloc)),
    _compare(other._compare)
  {
    _nil = _node_alloc.allocate(1);
    _nil->parent = _nil->leftChild = _nil->rightChild = _nil;
    _node_alloc.construct(_nil, node_type());
    _root = _copyTree(other._root, other._nil);
    _nil->parent = _maximum(_root);
  }

  virtual ~RBTree()
  {
     clear();
    _node_alloc.destroy(_nil);
    _node_alloc.deallocate(_nil, 1);
  }

  RBTree &operator=(const RBTree &other)
  {
    if (this != &other)
    {
      _destroyTree(_root);
      _root = _copyTree(other._root, other._nil);
      _size = other._size;
    }
    return *this;
  }

  /* *****************************************

      RB TREE MEMBER FUNCTIONS RELATED TO MAP

     ***************************************** */

  // CAPACITY

  bool empty() const { return size() == 0; }

  size_type size() const { return _size; }

  size_type max_size() const { return _alloc.max_size(); }

  // ITERATORS

  iterator begin() { return iterator(_minimum(_root), _nil); }

  const_iterator begin() const { return const_iterator(_minimum(_root), _nil); }

  iterator end() { return iterator(_nil, _nil); }

  const_iterator end() const { return const_iterator(_nil, _nil); }

  reverse_iterator rbegin() { return reverse_iterator(end()); }

  const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }

  reverse_iterator rend() { return reverse_iterator(begin()); }

  const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

  // MODIFIERS

  ft::pair<iterator, bool> insertUnique(const value_type &val)
  {
    return _insert(val, _root, _nil);
  }

  iterator insertUnique(iterator position, const value_type &val)
  {
    if (!_positionPrecedesValue(position, val))
      return _insert(val, _root, _nil).first;
    else
      return _insert(val, position._node, _nil).first;
  }

  template <class InputIterator>
  void insertUnique(InputIterator first, InputIterator last)
  {
    for (;first != last; first++)
      _insert(*first, _root, _nil);
  }

  void erase(iterator position)
  {
    if (position == end())
      return;
    _erase(position);
  }

  size_type erase(const key_type& k)
  {
    ft::pair<iterator, iterator> p = equal_range(k);
    const size_type oldSize = size();
    _erase(p.first, p.second);

    return oldSize - size();
  }

  void erase(iterator first, iterator last) { _erase(first, last); }

  void swap(RBTree &tree)
  {
    RBTree<Key, Val, KeyOfValue, Compare, Alloc> temp(tree);
    tree = *this;
    *this = temp;
  }

  void clear()
  {
    _destroyTree(_root);
    _root = _nil;
    _size = 0;
  }

  // OBSERVERS

  key_compare key_comp() const { return _compare; }

  // OPERATIONS

  iterator find(const key_type &k)
  {
    node_pointer node = _find(k);
    return iterator(node, _nil);
  }

  const_iterator find(const key_type &k) const
  {
    node_pointer node = _find(k);
    return const_iterator(node, _nil);
  }

  size_type count(const key_type &k) const
  {
    return _find(k) == _nil ? 0 : 1;
  }

  iterator lower_bound(const key_type &k)
  {
    return iterator(_lower_bound(k), _nil);
  }

  const_iterator lower_bound(const key_type &k) const
  {
    return const_iterator(_lower_bound(k), _nil);
  }

  iterator upper_bound(const key_type &k)
  {
    return iterator(_upper_bound(k), _nil);
  }

  const_iterator upper_bound(const key_type &k) const
  {
    return const_iterator(_upper_bound(k), _nil);
  }

  ft::pair<iterator, iterator>
  equal_range(const key_type &k)
  {
    return ft::make_pair(lower_bound(k), upper_bound(k));
  }

  ft::pair<const_iterator, const_iterator>
  equal_range(const key_type &k) const
  {
    return ft::make_pair(lower_bound(k), upper_bound(k));
  }

  // ALLOCATOR

  allocator_type get_allocator() const { return allocator_type(_alloc); }


private:

  const key_type _key(node_pointer node) const
  {
    return KeyOfValue()(*(node->content));
  }

  const key_type _key(value_type val) const { return KeyOfValue()(val); }

  node_pointer _find(const key_type &k) const
  {
    node_pointer node;
    node = _root;

    while (node != _nil)
    {
      const key_type nodeKey = _key(node);

      if (!_compare(k, nodeKey) && !_compare(nodeKey, k))
        return node;
      else if (_compare(k, nodeKey))
        node = node->leftChild;
      else
        node = node->rightChild;
    }

    return _nil;
  }

  node_pointer _lower_bound(const key_type &key) const
  {
    node_pointer x = _root;
    node_pointer y = _nil;

    while (x != _nil)
    {
      if (!_compare(_key(x), key))
      {
        y = x;
        x = x->leftChild;
      }
      else
        x = x->rightChild;
    }

    return y;
  }

  node_pointer _upper_bound(const key_type &key) const
  {
    node_pointer x = _root;
    node_pointer y = _nil;

    while (x != _nil)
    {
      if (_compare(key, _key(x)))
      {
        y = x;
        x = x->leftChild;
      }
      else
        x = x->rightChild;
    }

    return y;
  }

  bool _positionPrecedesValue(iterator position, const value_type& value)
  {
    return upper_bound(value.first)-- == position;
  }

  node_pointer _copyTree(
    const node_pointer &node,
    const node_pointer &treeCopyNil
  )
  {
    if (node == treeCopyNil)
      return _nil;

    node_pointer newNode = _node_alloc.allocate(1);

    _node_alloc.construct(newNode, *node);
    newNode->leftChild = _copyTree(node->leftChild, treeCopyNil);
    newNode->rightChild = _copyTree(node->rightChild, treeCopyNil);
    newNode->parent = _nil;

    if (newNode->leftChild != _nil)
      newNode->leftChild->parent = newNode;
    if (newNode->rightChild != _nil)
      newNode->rightChild->parent = newNode;

    return newNode;
  }

  void _destroyNode(node_pointer node)
  {
    _node_alloc.destroy(node);
    _node_alloc.deallocate(node, 1);
  }

  void _erase(iterator position)
  {
    node_pointer y = _remove(position._node);
    _destroyNode(y);
    --_size;
    _nil->parent = _maximum(_root);
  }

  void _erase(iterator first, iterator last)
  {
    if (first == begin() && last == end())
      clear();
    else
    {
      while (first != last)
        erase(first++);
    }
  }

  node_pointer _remove(node_pointer z)
  {
    node_pointer x;
    node_pointer y = z;
    Color yOriginalColor = y->color;

    if (z->leftChild == _nil) {
      x = z->rightChild;
      _transplant(z, z->rightChild);
    } else if (z->rightChild == _nil) {
      x = z->leftChild;
      _transplant(z, z->leftChild);
    } else {
      y = _minimum(z->rightChild);
      yOriginalColor = y->color;
      x = y->rightChild;

      if (y->parent == z)
        x->parent = y;
      else {
        _transplant(y, y->rightChild);
        y->rightChild = z->rightChild;
        y->rightChild->parent = y;
      }

      _transplant(z, y);
      y->leftChild = z->leftChild;
      y->leftChild->parent = y;
      y->color = z->color;
    }

    if (yOriginalColor == BLACK) {
      _remove_fixup(x);
    }

    return z;
  }

  void _transplant(node_pointer u, node_pointer v)
  {
    if (u->parent == _nil)
      _root = v;
    else if (u == u->parent->leftChild)
      u->parent->leftChild = v;
    else
      u->parent->rightChild = v;

    v->parent = u->parent;
  }

  void _remove_fixup(node_pointer x)
  {
    node_pointer w;

    while (x != _root && x->color == BLACK)
    {
      if (x == x->parent->leftChild)
      {
        w = x->parent->rightChild;

        if (w->color == RED)
        {
          w->color = BLACK;
          x->parent->color = RED;
          _leftRotate(x->parent);
          w = x->parent->rightChild;
        }
        if (w->leftChild->color == BLACK && w->rightChild->color == BLACK)
        {
          w->color = RED;
          x = x->parent;
        }
        else if (w->rightChild->color == BLACK)
        {
          w->leftChild->color = BLACK;
          w->color = RED;
          _rightRotate(w);
          w = x->parent->rightChild;
        }

        w->color = x->parent->color;
        x->parent->color = BLACK;
        w->rightChild->color = BLACK;
        _leftRotate(x->parent);
        x = _root;
      }
      else
      {
        w = x->parent->leftChild;
        if (w->color == RED)
        {
          w->color = BLACK;
          x->parent->color = RED;
          _rightRotate(x->parent);
          w = x->parent->leftChild;
        }
        if (w->rightChild->color == BLACK && w->leftChild->color == BLACK)
        {
          w->color = RED;
          x = x->parent;
        }
        else if (w->leftChild->color == BLACK)
        {
          w->rightChild->color = BLACK;
          w->color = RED;
          _leftRotate(w);
          w = x->parent->leftChild;
        }

        w->color = x->parent->color;
        x->parent->color = BLACK;
        w->leftChild->color = BLACK;
        _rightRotate(x->parent);
        x = _root;
      }
    }

    x->color = BLACK;
  }

  void _destroyTree(node_pointer node)
  {
    if (node != _nil)
    {
      _destroyTree(node->leftChild);
      _destroyTree(node->rightChild);
      _destroyNode(node);
    }
  }

  node_pointer _minimum(node_pointer node) const
  {
    if (node == _nil)
      return _nil;

    while (node->leftChild != _nil)
      node = node->leftChild;

    return node;
  }

  node_pointer _maximum(node_pointer node) const
  {
    if (node == _nil)
      return _nil;
    while (node->rightChild != _nil) {
      node = node->rightChild;
    }
    return node;
  }

  node_pointer _newNode(
    const value_type &value,
    const node_color color = RED
  )
  {
    node_pointer z = _node_alloc.allocate(1);
    _node_alloc.construct(z, node_type(value, color, _nil, _alloc));
    return z;
  }

  ft::pair<iterator, bool> _insert(
    const value_type &value,
    node_pointer x,
    node_pointer y
  )
  {
    while (x != _nil)
    {
      y = x;
      if (!_compare(_key(value), _key(x)) && !_compare(_key(x), _key(value)))
      {
        _nil->parent = _maximum(_root);
        return ft::make_pair(iterator(x, _nil), false);
      }
      else if (_compare(_key(value), _key(x)))
        x = x->leftChild;
      else
        x = x->rightChild;
    }

    node_pointer z = _newNode(value);
    z->parent = y;
    if (y == _nil)
      _root = z;
    else if (_compare(_key(z), _key(y)))
      y->leftChild = z;
    else
      y->rightChild = z;
    z->leftChild = _nil;
    z->rightChild = _nil;
    z->color = RED;
    _insertFixup(z);
    ++_size;
    _nil->parent = _maximum(_root);
    return ft::make_pair(iterator(z, _nil), true);
  }

  void _insertFixup(node_pointer z)
  {
    while (z->parent->color == RED)
    {
      if (z->parent == z->parent->parent->leftChild)
      {
        node_pointer y = z->parent->parent->rightChild;

        if (y->color == RED)
        {
          z->parent->color = BLACK;         // case 1
          y->color = BLACK;                 // case 1
          z->parent->parent->color = RED;   // case 1
          z = z->parent->parent;            // case 1
        }
        else
        {
          if (z == z->parent->rightChild)
          {
            z = z->parent;                  // case 2
            _leftRotate(z);                 // case 2
          }
          z->parent->color = BLACK;         // case 3
          z->parent->parent->color = RED;   // case 3
          _rightRotate(z->parent->parent);  // case 3
        }
      }
      else
      {
        node_pointer y = z->parent->parent->leftChild;
        if (y->color == RED)
        {
          z->parent->color = BLACK;
          y->color = BLACK;
          z->parent->parent->color = RED;
          z = z->parent->parent;
        }
        else
        {
          if (z == z->parent->leftChild)
          {
            z = z->parent;
            _rightRotate(z);
          }
          z->parent->color = BLACK;
          z->parent->parent->color = RED;
          _leftRotate(z->parent->parent);
        }
      }
    }
    _root->color = BLACK;
  }

  void _leftRotate(node_pointer x)
  {
    if (x == _nil || x->rightChild == _nil)
      return;

    node_pointer y = x->rightChild;
    x->rightChild = y->leftChild;

    if (y->leftChild != _nil)
      y->leftChild->parent = x;

    y->parent = x->parent;
    if (x->parent == _nil)
      _root = y;
    else if (x == x->parent->leftChild)
      x->parent->leftChild = y;
    else
      x->parent->rightChild = y;

    y->leftChild = x;
    x->parent = y;
  }

  void _rightRotate(node_pointer x)
  {
    if (x == _nil || x->leftChild == _nil)
      return;

    node_pointer y = x->leftChild;
    x->leftChild = y->rightChild;

    if (y->rightChild != _nil)
      y->rightChild->parent = x;

    y->parent = x->parent;
    if (x->parent == _nil)
      _root = y;
    else if (x == x->parent->rightChild)
      x->parent->rightChild = y;
    else
      x->parent->leftChild = y;

    y->rightChild = x;
    x->parent = y;
  }

};

}

#endif
