#ifndef TYPECONVERTER_HPP
# define TYPECONVERTER_HPP

# include <iostream>
# include <string>
# include <stdexcept>

class TypeConverter
{

	public:

		TypeConverter( std::string input );
		TypeConverter( TypeConverter const & src );
		~TypeConverter();

		TypeConverter &		operator=( TypeConverter const & rhs );

    std::string  getInput() const;

    void  convert() const;
    void  validate() const;
    char  toChar() const;
    int  toInt() const;
    float  toFloat() const;
    double  toDouble() const;

  private:

    TypeConverter();
    std::string _input;

    void  _validateChar() const;
    void  _validateInt() const;
    void  _validateFloat() const;
    void  _validateDouble() const;

    class NotValidInput : public std::exception {
      public:
        virtual const char* what() const throw()
        {
          return "Error: not_valid_input\n - usage: enter an argument char, int, float or double.";
        }
    };
};


std::ostream &			operator<<( std::ostream & o, TypeConverter const & i );

#endif /* *************************************************** TYPECONVERTER_H */
