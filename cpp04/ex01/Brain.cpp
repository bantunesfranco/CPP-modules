/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/12 11:34:43 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/12 12:21:32 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain default constructor" << std::endl;
}

Brain::Brain(const Brain& brain)
{
	*this = brain;
	std::cout << "Brain copy constructor" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain default destructor" << std::endl;
}

Brain&	Brain::operator=(const Brain& brain)
{
	if (*this != brain)
		this->_ideas = brain._ideas;
	std::cout << "Brain copy constructor" << std::endl;
	return (*this);
}