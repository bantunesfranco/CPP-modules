/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/29 14:35:01 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/29 17:25:13 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <random>
#include <iostream>

const char* Span::CannotAddElementException::what() const throw()
{
	return "Cannot Add Element: Span is full";
}

const char* Span::NotEnoughElementsException::what() const throw()
{
	return "Not Enough Elements in Span";
}

Span::Span(void) : _N(0)
{
	std::cout << "Default constructor" << std::endl;
}

Span::Span(unsigned int N) : _N(N)
{
	std::cout << "Default constructor" << std::endl;
}

Span::Span(const Span& src)
{
	std::cout << "Copy constructor" << std::endl;
	*this = src;
}

Span::~Span(void)
{
	std::cout << "Default destructor" << std::endl;
}

Span&	Span::operator=(const Span& src)
{
	std::cout << "Assignment operator" << std::endl;
	if (this != &src)
	{
		this->_N = src._N;
		this->_vec = src._vec;
	}
	return (*this);
}

void	Span::addNumber(int i)
{
	if (this->_vec.size() == this->_N)
		throw(CannotAddElementException());
	else
		this->_vec.push_back(i);
}

void	Span::fillSpan(int i, int j)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(i,j);

	std::vector<int>::iterator start = this->_vec.begin();
	std::vector<int>::iterator end = this->_vec.end();

	while (start != end)
	{
		int i = dist(rng);
		std::cout << "i = " << i << std::endl;
		this->addNumber(i);
		start++;
	}
}

size_t	Span::longestSpan(void)
{
	size_t	span = 0;
	if (this->_vec.size() < 2)
		throw(NotEnoughElementsException());
	for (std::vector<int>::iterator it = this->_vec.begin(); (it + 1) != this->_vec.end(); it++)
	{
		size_t diff = std::abs(*(it + 1) - *it);
		if (diff >= span)
			span = diff;
	}
	return (span);
}

size_t	Span::shortestSpan(void)
{
	size_t	span;
	if (this->_vec.size() < 2)
		throw(NotEnoughElementsException());
	for (std::vector<int>::iterator it = this->_vec.begin(); (it + 1) != this->_vec.end(); it++)
	{
		size_t diff = std::abs(*(it + 1) - *it);
		if (diff < span)
			span = diff;
	}
	return (span);
}
