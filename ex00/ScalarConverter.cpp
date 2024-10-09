/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:02:34 by akuburas          #+#    #+#             */
/*   Updated: 2024/10/09 13:15:13 by akuburas         ###   ########.fr       */
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
		return
	}
}