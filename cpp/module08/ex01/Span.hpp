#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <stdexcept>

class Span
{

public:
  Span();
  Span(unsigned int n);
  Span(Span const &src);
  ~Span();

  Span &operator=(Span const &rhs);

  void addNumber(int n);
  int shortestSpan() const;
  int longestSpan() const;
  unsigned int getSize() const;

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

private:
  int *_n;
  unsigned int _size;
  unsigned int _index;
};

std::ostream &operator<<(std::ostream &o, Span const &i);

#endif /* ************************************************************ SPAN_H */
