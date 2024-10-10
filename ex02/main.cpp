/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:37:44 by akuburas          #+#    #+#             */
/*   Updated: 2024/10/10 09:48:07 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TypeGeneratorAndIdentifier.hpp"

int	main()
{
	Base* base = generate();
	if (!base)
		return (1);
	std::cout << "Identifying pointer:" << std::endl;
	identify(base);
	std::cout << "Identifying reference:" << std::endl;
	identify(*base);
	delete base;

	for (int i = 0; i < 10; i++)
	{
		Base* base = generate();
		if (!base)
			return (1);
		std::cout << "Identifying pointer:" << std::endl;
		identify(base);
		std::cout << "Identifying reference:" << std::endl;
		identify(*base);
		delete base;
	}
	return (0);
}