/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_casting_test.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:32:21 by akuburas          #+#    #+#             */
/*   Updated: 2024/10/11 11:33:12 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

struct A 
{
	virtual ~A() = default;  // A needs a virtual destructor for polymorphic casting
	virtual void showA() const { std::cout << "This is A\n"; }
	};

struct B 
{
	virtual ~B() = default;  // B needs a virtual destructor for polymorphic casting
	virtual void showB() const { std::cout << "This is B\n"; }
	};

struct D : A, B 
{
	void showA() const override { std::cout << "This is A from D\n"; }
	void showB() const override { std::cout << "This is B from D\n"; }
	void showD() const { std::cout << "This is D\n"; }
	};

int main(void) 
{
	// Dynamically allocate a D object, but point to it with a B* pointer
	B* pb = new D();

	// Cross-casting: Casting from B* to A* via dynamic_cast
	A* pa = dynamic_cast<A*>(pb);  // OK because D inherits both A and B

	if (pa) {
		std::cout << "Cross-casting B* to A* succeeded!\n";
		pa->showA();  // Should call the showA() method from D
	} else {
		std::cout << "Cross-casting B* to A* failed!\n";
	}

	// Let's also verify that we can cast back to D* from either A* or B*
	D* pdFromA = dynamic_cast<D*>(pa);  // Downcasting A* to D*
	D* pdFromB = dynamic_cast<D*>(pb);  // Downcasting B* to D*

	if (pdFromA) {
		std::cout << "Downcasting A* to D* succeeded!\n";
		pdFromA->showD();
	} else {
		std::cout << "Downcasting A* to D* failed!\n";
	}

	if (pdFromB) {
		std::cout << "Downcasting B* to D* succeeded!\n";
		pdFromB->showD();
	} else {
		std::cout << "Downcasting B* to D* failed!\n";
	}

	delete pb;  // Clean up the dynamically allocated object
	return 0;
	}
