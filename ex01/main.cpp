/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:05:58 by akuburas          #+#    #+#             */
/*   Updated: 2024/10/10 08:10:56 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
#include "Data.hpp"

int	main()
{
	Data data;
	data.s1 = "Hello";
	data.n = 42;
	data.s2 = "World";
	data.f = 3.14f;

	uintptr_t raw = Serializer::serialize(&data);
	Data *ptr = Serializer::deserialize(raw);
	if (&data == ptr)
		std::cout << "Data is the same" << std::endl;
	else
		std::cout << "Data is different" << std::endl;
	std::cout << "s1: " << ptr->s1 << std::endl;
	std::cout << "n: " << ptr->n << std::endl;
	std::cout << "s2: " << ptr->s2 << std::endl;
	std::cout << "f: " << ptr->f << std::endl;

	return (0);
}