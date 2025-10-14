#include "ScalarConverter.hpp"
#include <cerrno>
#include <cstdlib>
#include <limits>
#include <cmath>
#include "ScalarConverter.hpp"
#include <cerrno>
#include <cstdlib>
#include <limits>
#include <cmath>

bool ScalarConverter::isChar(const std::string &input)
{
	return (input.length() == 3 && input[0] == '\'' && input[input.length() - 1] == '\'');
}

bool ScalarConverter::isPseudoLiteral(const std::string &input)
{
	return (input == "nan" || input == "nanf" || input == "+inf" || input == "+inff" || input == "-inf" || input == "-inff");
}

bool ScalarConverter::isInt(const std::string &input)
{
	size_t idx = 0;

	if (isPseudoLiteral(input))
		return false;
	if (input.empty())
		return false;
	if (input[0] == '-' || input[0] == '+')
		idx++;
	if (idx >= input.length())
		return false;
	for (; idx < input.length(); idx++)
	{
		if (!std::isdigit(input[idx]))
			return false;
	}
	return true;
}

bool ScalarConverter::isDouble(const std::string &input)
{
	size_t idx = 0, dot_count = 0;

	if (isPseudoLiteral(input))
		return true;
	if (input.empty())
		return false;
	if (input[0] == '-' || input[0] == '+')
		idx++;
	if (idx >= input.length())
		return false;
	for (; idx < input.length(); idx++)
	{
		if (input[idx] == '.')
		{
			dot_count++;
			if (dot_count > 1)
				return false;
		}
		else if (!std::isdigit(input[idx]))
			return false;
	}
	return dot_count == 1;
}

bool ScalarConverter::isFloat(const std::string &input)
{
	size_t idx = 0, dot_count = 0;

	if (input.length() < 2)
		return false;
	if (input[input.length() - 1] != 'f')
		return false;
	if (isPseudoLiteral(input))
		return true;
	if (input[0] == '-' || input[0] == '+')
		idx++;
	if (idx >= input.length() - 1)
		return false;
	for (; idx < input.length() - 1; idx++)
	{
		if (input[idx] == '.')
		{
			dot_count++;
			if (dot_count > 1)
				return false;
		}
		else if (!std::isdigit(input[idx]))
			return false;
	}
	return dot_count == 1;
}

bool ScalarConverter::isValidFormat(const std::string &input)
{
	if (input.empty())
		return false;
	return (isChar(input) || isFloat(input) || isDouble(input) || isInt(input));
}

void ScalarConverter::convert(const std::string &input)
{
	if (!isValidFormat(input))
	{
		std::cout << "Error: Type conversion is impossible" << std::endl;
		return ;
	}

	double value;
	bool overflow = false;
	
	if (isChar(input))
		value = static_cast<double>(input[1]);
	else if (isPseudoLiteral(input))
		value = std::strtod(input.c_str(), NULL);
	else
	{
		errno = 0;
		char* end;
		value = std::strtod(input.c_str(), &end);
		
		if (errno == ERANGE && (value == HUGE_VAL || value == -HUGE_VAL))
			overflow = true;
	}
	printChar(value, input, overflow);
	printInt(value, input, overflow);
	printFloat(value, input, overflow);
	printDouble(value, input, overflow);
}

void ScalarConverter::printChar(double value, const std::string &input, bool overflow)
{
	std::cout << "char: ";
	if (overflow || isPseudoLiteral(input) || std::isnan(value) || std::isinf(value))
		std::cout << "impossible" << std::endl;
	else if (value < 0 || value > 127)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << static_cast<char>(value) << std::endl;
}

void ScalarConverter::printInt(double value, const std::string &input, bool overflow)
{
	std::cout << "int: ";
	
	if (overflow || isPseudoLiteral(input) || std::isnan(value) || std::isinf(value))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}

	if (isInt(input))
	{
		errno = 0;
		char* end;
		long val = std::strtol(input.c_str(), &end, 10);
		
		if (errno == ERANGE || val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
		{
			std::cout << "impossible" << std::endl;
			return ;
		}
		std::cout << static_cast<int>(val) << std::endl;
	}
	else
	{
		if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
			std::cout << "impossible" << std::endl;
		else
			std::cout << static_cast<int>(value) << std::endl;
	}
}

void ScalarConverter::printFloat(double value, const std::string &input, bool overflow)
{
	std::cout << "float: ";
	(void)input;
	if (overflow)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (std::isnan(value))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(value))
	{
		if (value > 0)
			std::cout << "+inff" << std::endl;
		else
			std::cout << "-inff" << std::endl;
	}
	else if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max())
		std::cout << "impossible" << std::endl;
	else
	{
		float fVal = static_cast<float>(value);
		std::cout << std::fixed << std::setprecision(1) << fVal << "f" << std::endl;
	}
}
void ScalarConverter::printDouble(double value, const std::string &input, bool overflow)
{
	std::cout << "double: ";
	(void)input;
	if (overflow)
		std::cout << "impossible" << std::endl;
	else if (std::isnan(value))
		std::cout << "nan" << std::endl;
	else if (std::isinf(value))
	{
		if (value > 0)
			std::cout << "+inf" << std::endl;
		else
			std::cout << "-inf" << std::endl;
	}
	else
		std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}
