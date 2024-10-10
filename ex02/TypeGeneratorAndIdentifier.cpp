/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeGeneratorAndIdentifier.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:27:03 by akuburas          #+#    #+#             */
/*   Updated: 2024/10/10 09:31:34 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TypeGeneratorAndIdentifier.hpp"

Base* generate(void)
{
	std:srand(std::time(nullptr));
	int random = std::rand() % 3;
	try
	{
		switch (random)
		{
			case 0:
				std::cout << "Generated A" << std::endl;
				return new A();
			case 1:
				std::cout << "Generated B" << std::endl;
				return new B();
			case 2:
				std::cout << "Generated C" << std::endl;
				return new C();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return nullptr;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base& p)
{
	try
	{
		Base &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			Base &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				Base &c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "Unknown" << std::endl;
			}
		}
	}
}