#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cctype>
#include <limits>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cmath>

class ScalarConverter
{
private:
	ScalarConverter(/* args */);
	ScalarConverter(const ScalarConverter &obj);
	ScalarConverter &operator=(const ScalarConverter &obj);
	~ScalarConverter();
	static bool isPseudoLiteral(const std::string &input);
	static bool isValidFormat(const std::string &input);
	static bool isChar(const std::string &input);
	static bool isInt(const std::string &input);
	static bool isDouble(const std::string &input);
	static bool isFloat(const std::string &input);
	static void print(double dFloat, double dInt, double dChar, double dDouble, const std::string &input);
public:
	static void convert(const std::string &input);
};


#endif