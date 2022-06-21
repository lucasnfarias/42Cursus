#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <stdexcept>
# include <limits.h>

class Span
{

public:
  Span();
  Span(unsigned int n);
  Span(Span const &src);
  ~Span();

  Span &operator=(Span const &rhs);

  int &operator[](unsigned int i) const;

  void addNumber(int n);
  void addNumber(std::vector<int>::iterator firstNumber, std::vector<int>::iterator lastNumber);
  int shortestSpan() const;
  int longestSpan() const;
  unsigned int getSize() const;
  unsigned int getCapacity() const;

  class NoMoreSpaceException : public std::exception
  {
  public:
    virtual const char *what() const throw()
    {
      return ("Error: span is full. No more space left :(");
    }
  };

  class NotEnoughElementsException : public std::exception
  {
  public:
    virtual const char *what() const throw()
    {
      return ("Error: there is not enough elements to calculate the span.");
    }
  };

  class IndexOutOfRangeException : public std::exception
  {
  public:
    virtual const char *what() const throw()
    {
      return ("Error: index out of range.");
    }
  };

private:
  unsigned int _size;
  unsigned int _capacity;
  std::vector<int> *_n;
  void  checkSpace() const;
};

std::ostream &operator<<(std::ostream &o, Span const &i);

#endif /* ************************************************************ SPAN_H */
