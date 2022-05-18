#ifndef TYPECONVERTER_HPP
# define TYPECONVERTER_HPP

# include <iostream>
# include <string>
# include <stdexcept>

# define RESET    "\033[0m"
# define RED      "\033[31m"
# define YELLOW   "\033[33m"
# define PURPLE     "\033[34m"

enum LogLevel {
  Error = 0, Warning, Info
};

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

    bool  _validateChar() const;
    bool  _validateInt() const;
    bool  _validateFloat() const;
    bool  _validateDouble() const;

    void  _createLog(LogLevel level, std::string message) const;

    class NotValidInput : public std::exception {
      public:
        virtual const char* what() const throw()
        {
          return "not_valid_input\n- usage: enter an argument char, int, float or double.";
        }
    };
};


std::ostream &			operator<<( std::ostream & o, TypeConverter const & i );

#endif /* *************************************************** TYPECONVERTER_H */
