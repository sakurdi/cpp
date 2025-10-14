#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cctype>
#include <limits>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <cerrno>

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
	static void printChar(double value, const std::string &input, bool overflow);
	static void printInt(double value, const std::string &input, bool overflow);
	static void printFloat(double value, const std::string &input, bool overflow);
	static void printDouble(double value, const std::string &input, bool overflow);
public:
	static void convert(const std::string &input);
};


#endif
