/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:02:34 by akuburas          #+#    #+#             */
/*   Updated: 2024/10/09 15:42:25 by akuburas         ###   ########.fr       */
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
	return *end == 'f'
	
}

bool ScalarConverter::isDouble(const std::string &literal)
{
	
}