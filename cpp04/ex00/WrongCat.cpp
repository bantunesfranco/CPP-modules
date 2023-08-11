/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 18:52:03 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/11 19:03:15 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongcat) : WrongAnimal(wrongcat.getType())
{
	*this = wrongcat;
	std::cout << "WrongCat copy constructor" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat default destructor" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& wrongcat)
{
	if (this != &wrongcat)
		this->_type = wrongcat.getType();
	std::cout << "WrongCat copy constructor" << std::endl;
	return (*this);
}
void	WrongCat::makeSound(void) const
{
	std::cout << "Miau Miau" << std::endl;
}
