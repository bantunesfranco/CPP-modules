/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 14:26:21 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/11 19:02:55 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main(void)
{
	const Animal*	dog = new Dog();
	const Animal*	cat = new Cat();
	const Animal*	animal = new Animal();

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << animal->getType() << " " << std::endl;
	
	dog->makeSound();
	cat->makeSound();
	animal->makeSound();
	delete dog;
	delete cat;
	delete animal;

	std::cout << "" << std::endl;

	Dog*	newDog = new Dog();
	Dog*	newDog2 = NULL;
	
	newDog2 = newDog;
	newDog2->makeSound();
	std::cout << newDog << "\n" << newDog2 << std::endl;
	delete newDog2;
	std::cout << "" << std::endl;

	Cat*	newCat = new Cat();
	Cat*	newCat2 = new Cat(*newCat);

	newCat2->makeSound();
	std::cout << newCat << "\n" << newCat2 << std::endl;
	delete newCat;
	delete newCat2;

	std::cout << "" << std::endl;

	const WrongAnimal*	wrongcat = new WrongCat();
	const WrongAnimal*	wronganimal = new WrongAnimal();

	std::cout << wrongcat->getType() << " " << std::endl;
	std::cout << wronganimal->getType() << " " << std::endl;
	
	wrongcat->makeSound();
	wronganimal->makeSound();
	delete wrongcat;
	delete wronganimal;

	return (0);
}
