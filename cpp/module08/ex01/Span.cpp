#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span()
{
}

Span::Span(unsigned int n) : _n(new int[n])
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

void addNumber(int n)
{
  (void)n;
  // throw exception if span is full
  // implement also another addNumber w/ range of iterators
}

int shortestSpan()
{
  // throw exception if span has only one or zero numbers
  return 0;
}

int longestSpan()
{
  // throw exception if span has only one or zero numbers
  return 0;
}



/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
