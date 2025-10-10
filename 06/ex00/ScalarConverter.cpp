#include "ScalarConverter.hpp"

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

	if (!std::isdigit(input[input.length() - 1]))
		return false;

	if (isPseudoLiteral(input))
		return true;

	if (input[0] == '-')
		idx++;
	for (; idx < input.length(); idx++)
	{
		if (!std::isdigit(input[idx]) && input[idx] != '.')
			return false;
	}
	return true;
}

bool ScalarConverter::isDouble(const std::string &input)
{
	size_t idx = 0, dot_count = 0;

	if (!std::isdigit(input[input.length() - 1]))
		return false;

	if (isPseudoLiteral(input))
		return true;

	if (input[0] == '-')
		idx++;
	for (; idx < input.length(); idx++)
	{
		if (dot_count > 1)
			return false;
		if (!std::isdigit(input[idx]) && input[idx] != '.')
			return false;
		if (input[idx] == '.')
			dot_count++;
	}
	return true && dot_count;
}

bool ScalarConverter::isFloat(const std::string &input)
{
	size_t idx = 0, dot_count = 0;

	if (input[input.length() - 1] != 'f')
		return false;

	if (isPseudoLiteral(input))
		return true;

	if (input[0] == '-')
		idx++;
	for (; idx < input.length() - 1; idx++)
	{
		if (dot_count > 1)
			return false;
		if (!std::isdigit(input[idx]) && input[idx] != '.')
			return false;
		if (input[idx] == '.')
			dot_count++;
	}
	return true && dot_count;
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

	double dFloat = std::atof(input.c_str());
	double dInt = static_cast<double>(std::atoi(input.c_str()));
	double dChar;
	if (isChar(input))
		dChar = static_cast<double>(input[1]);
	else
		dChar = std::atof(input.c_str());
	double dDouble = std::atof(input.c_str());
	print(dFloat, dInt, dChar, dDouble, input);
}

void ScalarConverter::print(double dFloat, double dInt, double dChar, double dDouble, const std::string &input)
{
	char c = static_cast<char>(dChar);
	std::cout << "char: ";
	if (isPseudoLiteral(input))
		std::cout << "impossible" << std::endl;
	else if (dChar < 0 || dChar > 127)
		std::cout << "impossible"<< std::endl;
	else if (!std::isprint(c))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << c << std::endl;

	int n = static_cast<int>(dInt);
	std::cout << "int: ";
	if (isPseudoLiteral(input))
		std::cout << "impossible" << std::endl;
	else if (dInt < std::numeric_limits<int>::min() || dInt > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << n << std::endl;

	float fVal = static_cast<float>(dFloat);
	std::cout << "float: ";
	if (std::isnan(dFloat))
		std::cout << "nanf" << std::endl;
	else if(std::isinf(dFloat))
	{
		if(dFloat > 0)
			std::cout << "+inff" << std::endl;
		else
			std::cout << "-inff" << std::endl;
	}
	else
		std::cout << std::fixed << std::setprecision(1) << fVal << "f" << std::endl;

	double dVal = static_cast<double>(dDouble);
	std::cout << "double: ";
	if (std::isnan(dDouble))
		std::cout << "nan" << std::endl;
	else if(std::isinf(dDouble))
	{
		if(dDouble > 0)
			std::cout << "+inf" << std::endl;
		else
			std::cout << "-inf" << std::endl;
	}
	else
		std::cout << dVal << std::endl;
}