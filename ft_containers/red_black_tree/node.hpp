/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:35:48 by lniehues          #+#    #+#             */
/*   Updated: 2022/09/30 21:12:15 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

# include <cstddef>
# include <memory>


namespace ft {

enum Color { RED = 0, BLACK = 1 };

template <class T, class Alloc = std::allocator<T> >
class Node
{
public:
  typedef T         value_type;
  typedef T         *pointer;
  typedef T         &reference;
  typedef const T   *const_pointer;
  typedef const T   &const_reference;
  typedef Node<T>   *node_pointer;
  typedef Alloc     allocator_type;
  typedef Color     color_type;

  pointer           content;
  node_pointer      parent;
  node_pointer      leftChild;
  node_pointer      rightChild;
  color_type        color;
  allocator_type    alloc;
  bool              unitialized;

  explicit Node(
    color_type color = BLACK,
    node_pointer parent = NULL,
    node_pointer leftChild = NULL,
    node_pointer rightChild = NULL,
    allocator_type alloc = allocator_type()
  )
  :
    content(NULL),
    parent(parent),
    leftChild(leftChild),
    rightChild(rightChild),
    color(color),
    alloc(alloc),
    unitialized(true)
  {}

  Node(
    value_type value,
    color_type color,
    node_pointer nil,
    allocator_type alloc = allocator_type()
  )
  :
    parent(nil),
    leftChild(nil),
    rightChild(nil),
    color(color),
    alloc(alloc),
    unitialized(false)
  {
    content = alloc.allocate(1);
    alloc.construct(content, value);
  }

  Node(const Node &other)
  :
    parent(other.parent),
    leftChild(other.leftChild),
    rightChild(other.rightChild),
    color(other.color),
    alloc(other.alloc),
    unitialized(true)
  {
    content = alloc.allocate(1);
    if (other.content != NULL) {
      alloc.construct(content, *other.content);
      unitialized = false;
    }
  }

  Node &operator=(const Node &rhs)
  {
    if (this != &rhs)
    {
      if (rhs.content != NULL)
      {
        if (content != NULL)
        {
          alloc.destroy(content);
          alloc.deallocate(content, 1);
        }
        content = alloc.allocate(1);
        alloc.construct(content, *rhs.content);
      }
      else
      {
        if (content != NULL)
        {
          alloc.destroy(content);
          alloc.deallocate(content, 1);
        }
        content = NULL;
      }

      parent = rhs.parent;
      leftChild = rhs.leftChild;
      rightChild = rhs.rightChild;
      color = rhs.color;
    }

    return *this;
  }

  virtual ~Node()
  {
    if (!unitialized)
      alloc.destroy(content);

    alloc.deallocate(content, 1);
  }
};

}

#endif
