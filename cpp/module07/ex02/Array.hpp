#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <stdexcept>

template <typename T = int>
class Array
{

public:
  Array<T>() : _n(0), _pointer(0){};
  Array<T>(unsigned int n) : _n(n), _pointer(new T[n]()){};
  Array<T>(Array const &src) : _n(src.size()), _pointer(new T[_n]())
  {
    *this = src;
  };
  ~Array<T>()
  {
    if (_pointer)
      delete[] _pointer;
  };

  Array &operator=(Array const &rhs)
  {
    try
    {
      for (unsigned int i = 0; i < rhs.size(); i++)
      {
        if (i >= _n)
          throw IndexOutOfBoundsException();
        _pointer[i] = rhs._pointer[i];
      }
    }
    catch (const std::exception &e)
    {
      std::cout
      << "Copied first " << _n << " elements. No more space in this array :("
      << std::endl;
      std::cerr << e.what() << std::endl;
    }
    return *this;
  };

  T &operator[](unsigned int const &index)
  {
    if (index >= _n)
      throw IndexOutOfBoundsException();

    return _pointer[index];
  };

  unsigned int size() const { return _n; };

  class IndexOutOfBoundsException : public std::exception
  {
  public:
    virtual const char *what() const throw()
    {
      return ("Error: index out of bounds.");
    }
  };

private:
  unsigned int _n;
  T *_pointer;
};

template <typename T>
std::ostream &operator<<(std::ostream &o, Array<T> const &i)
{
  o << "array size: " <<i.size();

  return o;
}

#endif /* *********************************************************** ARRAY_H */
