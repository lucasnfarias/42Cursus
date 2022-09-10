/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:37:06 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/10 20:35:20 by lniehues         ###   ########.fr       */
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
  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;
  typedef TreeIterator<value_type> iterator;
  typedef ConstTreeIterator<value_type> const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
  // typedef std::allocator<node_type> node_allocator_type;

private:
  typedef typename Alloc::template rebind< Node<value_type> >::other
    node_allocator_type;
  // VER SE ISSO AQUI DÁ CERTO , qualquer coisa volta pra como é na linha 50

  size_type _size;
  allocator_type _alloc;
  node_allocator_type _node_alloc;
  key_compare _comp;

  node_pointer _root;
  node_pointer _nil;

public:
  explicit RBTree(
    const key_compare &comp = key_compare(),
    const allocator_type &alloc = allocator_type()
  )
  :
    _node_alloc(node_allocator_type()),
    _alloc(alloc),
    _comp(comp),
    _size(0)
  {
    _nil = _node_alloc.allocate(1);
    _node_alloc.construct(_nil, node_type());
    _nil->parent = _nil->leftChild = _nil->rightChild = _nil;
    _root = _nil;
  };

  RBTree(const RBTree &other)
  :
    _node_alloc(node_allocator_type(other._node_alloc)),
    _alloc(allocator_type(other._alloc)),
    _comp(other._comp),
    _size(other._size)
  {
    _nil = _node_alloc.allocate(1);
    _nil->parent = _nil->leftChild = _nil->rightChild = _nil;
    _node_alloc.construct(_nil, node_type());
  };

  virtual ~RBTree()
  {
     clear();
    _node_alloc.destroy(_nil);
    _node_alloc.deallocate(_nil, 1);
  };

  RBTree &operator=(const RBTree &other)
  {
    if (this != &other)
    {
      _destroy_tree(_root);
      _root = _copy_tree(other._root, other._nil);
      _size = other._size;
    }
    return *this;
  };

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

  const_reverse_iterator rbegin() const {
    return const_reverse_iterator(end());
  }

  reverse_iterator rend() { return reverse_iterator(begin()); }

  const_reverse_iterator rend() const {
    return const_reverse_iterator(begin());
  }

  void clear()
  {
    _destroy_tree(_root);
    _root = _nil;
    _size = 0;
  }

private:
    node_pointer _copy_tree(
      const node_pointer &node,
      const node_pointer &tree_copy_nil
    )
    {
    if (node == tree_copy_nil)
      return _nil;

    node_pointer new_node = _node_alloc.allocate(1);
    _node_alloc.construct(new_node, *node);
    new_node->leftChild = _copy_tree(node->leftChild, tree_copy_nil);
    new_node->rightChild = _copy_tree(node->rightChild, tree_copy_nil);
    new_node->parent = _nil;
    if (new_node->leftChild != _nil)
      new_node->leftChild->parent = new_node;
    if (new_node->rightChild != _nil)
      new_node->rightChild->parent = new_node;
    return new_node;
  }

  void _destroy_tree(node_pointer node)
  {
    if (node != _nil) {
      _destroy_tree(node->leftChild);
      _destroy_tree(node->rightChild);
      _destroy_node(node);
    }
  }

  void _destroy_node(node_pointer node)
  {
    _node_alloc.destroy(node);
    _node_alloc.deallocate(node, 1);
  }

  node_pointer _minimum(node_pointer node) const
  {
    if (node == _nil)
      return _nil;
    while (node->leftChild != _nil) {
      node = node->leftChild;
    }
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
};

}

#endif
