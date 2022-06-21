#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <stdexcept>

template <typename T = int>
class Array
{

public:
  Array() : _n(0), _pointer(0){};
  Array(unsigned int n) : _n(n), _pointer(new T[n]()){};
  Array(Array const &src) : _n(src.size()), _pointer(new T[_n]())
  {
    *this = src;
  };
  ~Array()
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

  T &operator[](unsigned int const &index) const
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
  o << "array size: " << i.size();

  return o;
}

template <typename T>
void printArray(Array<T> &array, std::string arrayName = "intArray")
{
  if (array.size() == 0)
    std::cout << arrayName << " is an empty array." << std::endl;

  for (unsigned int i = 0; i < array.size(); i++)
  {
    try
    {
      std::cout << arrayName << "[" << i << "] = " << array[i] << std::endl;
    }
    catch (const std::exception &e)
    {
      std::cerr << e.what() << std::endl;
    }
  }
  std::cout << std::endl;
}

template <typename T>
void printArray(Array<T> const &array, std::string arrayName = "intArray")
{
  if (array.size() == 0)
    std::cout << arrayName << " is an empty array." << std::endl;

  for (unsigned int i = 0; i < array.size(); i++)
  {
    try
    {
      std::cout << arrayName << "[" << i << "] = " << array[i] << std::endl;
    }
    catch (const std::exception &e)
    {
      std::cerr << e.what() << std::endl;
    }
  }
  std::cout << std::endl;
}

void enterToContinue()
{
  std::cout << "\nPress enter to continue...\n";
  std::cin.ignore();
}

class Example
{
public:
  Example() : _name("Marvin"){};
  Example(std::string name) : _name(name){};
  ~Example(){};

  std::string getName() const { return _name; };

private:
  std::string _name;
};

std::ostream &operator<<(std::ostream &o, Example const &i)
{
  o << "My name is " << i.getName();

  return o;
}

#endif /* *********************************************************** ARRAY_H */
