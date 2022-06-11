#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span() : _n(0), _size(0), _index(0)
{
}

Span::Span(unsigned int n) : _n(new int[n]), _size(n), _index(0)
{
}


Span::Span( const Span & src )
{
  (void)src;
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

Span &				Span::operator=( Span const & rhs )
{
  (void)rhs;
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Span const & i )
{
  (void)i;
	o << "I'm just a Span of numbers.";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Span::addNumber(int n)
{
  if (_index >= _size)
    throw NoMoreSpaceException();
  _n[_index] = n;
  _index++;
  // implement also another addNumber w/ range of iterators
}

int Span::shortestSpan() const
{
  // throw exception if span has only one or zero numbers
  return 0;
}

int Span::longestSpan() const
{
  if (_index <= 1)
    throw NotEnoughElementsException();
  int* min = std::min_element(_n, _n+_index);
  int* max = std::max_element(_n, _n+_index);
  return (*max - *min);
}

unsigned int Span::getSize() const
{
  return _size;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
