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

enum  inputType {
  NONE = 0, CHAR, INT, FLOAT, DOUBLE, PSEUDO_LITERAL
};

class TypeConverter
{

	public:

		TypeConverter( std::string input );
		TypeConverter( TypeConverter const & src );
		~TypeConverter();

		TypeConverter &		operator=( TypeConverter const & rhs );

    std::string  getInput() const;
    inputType  getType() const;

    void  convert() const;
    void  validate();

  private:

    TypeConverter();
    std::string _input;
    inputType _type;

    bool  _validateChar();
    bool  _validateInt();
    bool  _validateFloat();
    bool  _validateDouble();

    void  _fromChar() const;
    void  _fromPseudoLiteral() const;
    void  _fromInt() const;
    void  _fromFloat() const;
    void  _fromDouble() const;

    void  _createLog(LogLevel level, std::string message) const;
    void  _printValue(std::string type, std::string value = "impossible") const;
    void  _printValue(std::string type, char value) const;
    void  _printValue(std::string type, int value) const;
    void  _printValue(std::string type, float value) const;
    void  _printValue(std::string type, double value) const;

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
