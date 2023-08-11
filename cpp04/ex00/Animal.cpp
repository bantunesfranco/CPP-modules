/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 14:18:07 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/11 14:36:07 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.cpp"
#include <iostream>

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal default constructor" << std::endl;
}

Animal::Animal(const Animal& animal)
{
	*this = animal;
	std::cout << "Animal copy constructor" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal default destructor" << std::endl;
}