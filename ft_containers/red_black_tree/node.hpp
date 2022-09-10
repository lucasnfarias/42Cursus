/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rhs.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:35:48 by lniehues          #+#    #+#             */
/*   Updated: 2022/08/18 21:11:20 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

# include <cstddef>
# include <memory>


namespace ft {

enum Color { RED = 0, BLACK = 1 };

template <class T, class Alloc = std::allocator<T>>
class Node
{
public:
  typedef T         value_type;
  typedef T         *pointer;
  typedef T         &reference;
  typedef const T   *const_pointer;
  typedef const T   &const_reference;
  typedef Node<T>   *node_ptr;
  typedef Alloc     allocator_type;
  typedef Color     color_type;

  color_type      color;
  node_ptr        leftChild;
  node_ptr        rightChild;
  node_ptr        parent;
  pointer         content;
  allocator_type  alloc;
  // check if it will need an aux node after/during creating the rb tree logic :)

  explicit Node(
    color_type color = BLACK,
    node_ptr parent = NULL,
    node_ptr leftChild = NULL,
    node_ptr rightChild = NULL,
    allocator_type alloc = allocator_type()
  )
  : content(NULL),
    parent(parent),
    leftChild(leftChild),
    rightChild(rightChild),
    color(color),
    alloc(alloc)
  {}

  Node(
    value_type value,
    color_type color,
    node_ptr nil,
    allocator_type alloc = allocator_type()
  )
  :
    alloc(alloc),
    parent(nil),
    leftChild(nil),
    rightChild(nil),
    color(color)
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
    alloc(other.alloc)
  {
    content = alloc.allocate(1);
    if (other.content != NULL)
      alloc.construct(content, *other.content);
  }

  Node &operator=(const Node &rhs)
  {
    if (this != &rhs)
    {
      if (content != NULL)
      {
        alloc.destroy(content);
        alloc.deallocate(content, 1);
        content = NULL;
      }

      if (rhs.content != NULL)
      {
        content = alloc.allocate(1);
        alloc.construct(content, *rhs.content);
      }

      parent = rhs.parent;
      leftChild = rhs.leftChild;
      rightChild = rhs.rightChild;
      color = rhs.color;
    }

    return *this;
  }

  virtual ~Node() {
    if (content != NULL)
      alloc.destroy(content);

    alloc.deallocate(content, 1);
  }
};

}

#endif
