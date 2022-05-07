#ifndef TYPECONVERTER_HPP
# define TYPECONVERTER_HPP

# include <iostream>
# include <string>

class TypeConverter
{

	public:

		TypeConverter();
		TypeConverter( TypeConverter const & src );
		~TypeConverter();

		TypeConverter &		operator=( TypeConverter const & rhs );

    void  convertAll(char* value) const;
    char  toChar(char* value) const;
    int  toInt(char* value) const;
    float  toFloat(char* value) const;
    double  toDouble(char* value) const;
	private:

};


std::ostream &			operator<<( std::ostream & o, TypeConverter const & i );

#endif /* *************************************************** TYPECONVERTER_H */
