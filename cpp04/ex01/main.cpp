/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 14:26:21 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/01 17:49:17 by bfranco       ########   odam.nl         */
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
	dog1->setIdea(0, "Am good doggo");
	dog1->setIdea(1, "Am not bad doggo");
	Dog* 	dog2 = new Dog(*dog1);
	dog1->setIdea(0, "Munchies");
	dog2->setIdea(1, "Am very good doggo");
	std::cout << "Address dog1 = " << dog1 << std::endl;
	dog1->getIdeas();
	std::cout << "Address dog2 = " << dog2 << std::endl;
	dog2->getIdeas();
	delete dog1;
	delete dog2;

	std::cout << "" << std::endl;

	Cat* 	cat1 = new Cat();
	Cat*	cat2 = NULL;
	cat2 = cat1;
	std::cout << "Address cat1 = " << cat1 << std::endl;
	cat1->setIdea(1, "Am good catto");
	cat1->getIdeas();
	cat2->getIdeas();
	std::cout << "Address cat2 = " << cat2 << std::endl;
	cat1->setIdea(1, "Am not good catto");
	cat1->getIdeas();
	cat2->getIdeas();
	cat1->setIdea(101, "Am hungry");
	delete cat2;

	return (0);
}
