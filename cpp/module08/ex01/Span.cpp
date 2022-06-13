#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span() : _size(0), _capacity(0)
{
}

Span::Span(unsigned int n) : _size(0), _capacity(n), _n(new std::vector<int>[n])
{
}

Span::Span(const Span &src) : _size(src.getSize()), _capacity(src.getCapacity()), _n(new std::vector<int>[_capacity])
{
  *this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
  if (_n)
    delete[] _n;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &Span::operator=(Span const &rhs)
{
  for (unsigned int i = 0; i < getSize(); i++)
    _n->push_back(rhs._n->at(i));
  return *this;
}

std::ostream &operator<<(std::ostream &o, Span const &i)
{
  o
      << "I'm just a Span of numbers with size "
      << i.getSize()
      << " and total capacity of "
      << i.getCapacity();

  return o;
}

int &Span::operator[](unsigned int i) const
{
  if (i >= _size)
    throw IndexOutOfRangeException();
  return _n->at(i);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Span::checkSpace() const
{
  if (_size >= _capacity)
    throw NoMoreSpaceException();
}

void Span::addNumber(int n)
{
  checkSpace();
  _n->push_back(n);
  _size++;
}

void Span::addNumber(std::vector<int>::iterator firstNumber, std::vector<int>::iterator lastNumber)
{
  try
  {
    for (std::vector<int>::iterator it = firstNumber; it != lastNumber; it++)
    {
      checkSpace();
      _n->push_back(*it);
      _size++;
    }
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }
}

int Span::shortestSpan() const
{
  if (_size <= 1)
    throw NotEnoughElementsException();

  int diff = INT_MAX;
  std::vector<int> numbersSorted(_n->begin(), _n->end());
  std::sort(numbersSorted.begin(), numbersSorted.end());

  for (std::vector<int>::iterator it = numbersSorted.begin(); it < numbersSorted.end() - 1; it++)
    if (*(it + 1) - *it < diff)
      diff = *(it + 1) - *it;

  return diff;
}

int Span::longestSpan() const
{
  if (_size <= 1)
    throw NotEnoughElementsException();
  std::vector<int>::iterator min = std::min_element(_n->begin(), _n->end());
  std::vector<int>::iterator max = std::max_element(_n->begin(), _n->end());
  return (*max - *min);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

unsigned int Span::getSize() const
{
  return _size;
}

unsigned int Span::getCapacity() const
{
  return _capacity;
}

/* ************************************************************************** */
