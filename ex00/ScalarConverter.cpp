/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:02:34 by akuburas          #+#    #+#             */
/*   Updated: 2024/10/10 07:14:48 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &literal)
{
	double value = 0.0;

	if (isChar(literal))
		value = static_cast<double>(literal[0]);
	else if (isInt(literal))
		value = std::strtol(literal.c_str(), nullptr, 10);
	else if (isFloat(literal))
		value = std::strtof(literal.c_str(), nullptr);
	else if (isDouble(literal))
		value = std::strtod(literal.c_str(), nullptr);
	else
	{
		std::cout << "impossible conversion!" << std::endl;
		return;
	}
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

bool ScalarConverter::isChar(const std::string &literal)
{
	return (literal.length() == 1 && !std::isdigit(literal[0]));
}

bool ScalarConverter::isInt(const std::string &literal)
{
	char *end;
	std::strtol(literal.c_str(), &end, 10);
	return (*end == '\0');
}

bool ScalarConverter::isFloat(const std::string &literal)
{
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return true;
	char *end;
	std::strtof(literal.c_str(), &end);
	return (*end == 'f');
	
}

bool ScalarConverter::isDouble(const std::string &literal)
{
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return true;
	char *end;
	std::strtod(literal.c_str(), &end);
	return (*end == '\0');
}

void ScalarConverter::printChar(double value)
{
	std::cout << "char: ";
	if (std::isnan(value) || value < 0 || value > std::numeric_limits<char>::max())
		std::cout << "impossible" << std::endl;
	else if (std::isprint(value))
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void ScalarConverter::printInt(double value)
{
	std::cout << "int: ";
	if (std::isnan(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value)
{
	std::cout << "float: ";
	if ((value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max()) && !std::isinf(value))
		std::cout << "impossible" << std::endl;
	else
	{
		float floatValue = static_cast<float>(value);
		if (floatValue == static_cast<int>(floatValue) && floatValue < std::numeric_limits<float>::max())
			std::cout << floatValue << ".0f" << std::endl;
		else
			std::cout << floatValue << "f" << std::endl;
	}
}

void ScalarConverter::printDouble(double value)
{
	std::cout << "double: ";
	if ((value < -std::numeric_limits<double>::max() || value > std::numeric_limits<double>::max()) && !std::isinf(value))
		std::cout << "impossible" << std::endl;
	else
	{
		if (value == static_cast<int>(value) && value < std::numeric_limits<double>::max())
			std::cout << value << ".0" << std::endl;
		else
			std::cout << value << std::endl;
	}
}