/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/12 11:34:43 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/14 15:27:15 by bfranco       ########   odam.nl         */
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
	if (this != &brain)
	{
		for (int i = 0; i < 100; i++)
		{
			if (brain._ideas[i].length() > 0)	
				this->_ideas[i].assign(brain._ideas[i]);
		}
	}
	std::cout << "Brain copy constructor" << std::endl;
	return (*this);
}

const std::string*	Brain::getIdeaAddress(size_t i) const
{
	if (i < 100)
	{
		const std::string&	idea = this->_ideas[i];
		return (&idea);
	}
	std::cout << "Index out of range" << std::endl;
	return (NULL);
}

const std::string	Brain::getIdea(size_t i) const
{
	if (i < 100)
		return(this->_ideas[i]);
	std::cout << "Index out of range" << std::endl;
	return (NULL);
}

void			Brain::setIdea(size_t i, std::string idea)
{
	if (i < 100)
		this->_ideas[i] = idea;
	else
		std::cout << "Index out of range" << std::endl;
}
