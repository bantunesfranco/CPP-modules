/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 14:26:21 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/13 20:18:34 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main(void)
{
	const Animal*	dog = new Dog();
	const Animal*	cat = new Cat();

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	dog->makeSound();
	cat->makeSound();
	delete dog;
	delete cat;

	std::cout << "" << std::endl;

	Animal* arr[100];

	for (int i = 0; i < 50; i++)
		arr[i] = new Dog();
	for (int i = 50; i < 100; i++)
		arr[i] = new Cat();
	for (int i = 0; i < 100; i++)
		arr[i]->makeSound();
	for (int i = 0; i < 100; i++)
		delete arr[i];

	std::cout << "" << std::endl;

	Dog* 	dog1 = new Dog();
	Dog* 	dog2 = new Dog(*dog1);
	std::cout << "Address dog1 = " << dog1 << std::endl;
	std::cout << "Address dog2 = " << dog2 << std::endl;
	dog1->setIdea("Am good doggo");
	delete dog1;
	delete dog2;

	std::cout << "" << std::endl;

	Cat* 	cat1 = new Cat();
	Cat*	cat2 = NULL;
	cat2 = cat1;
	std::cout << "Address cat1 = " << cat1 << std::endl;
	std::cout << "Address cat2 = " << cat2 << std::endl;
	delete cat2;

	return (0);
}
