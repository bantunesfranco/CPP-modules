/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/29 14:35:01 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/31 11:37:42 by bfranco       ########   odam.nl         */
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

void	Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	if (this->_vec.size() + std::distance(start, end) > this->_N)
		throw(CannotAddElementException());
	else
	{
		for (int i = 0; start + i != end; i++)
		this->_vec.push_back(*(start + i));
	}
}

size_t	Span::longestSpan(void)
{
	if (this->_vec.size() < 2)
		throw(NotEnoughElementsException());

	std::vector<int>::iterator start = this->_vec.begin();
	std::vector<int>::iterator end = this->_vec.end();
	std::sort(start, end);

	size_t	span = *std::max_element(start, end) - *std::min_element(start, end);
	return (span);
}

size_t	Span::shortestSpan(void)
{
	if (this->_vec.size() < 2)
		throw(NotEnoughElementsException());

	std::vector<int> diff;
	std::vector<int>::iterator start = this->_vec.begin();
	std::vector<int>::iterator end = this->_vec.end();

	std::sort(start, end);

	for (std::vector<int>::iterator it = start; (it + 1) != end; it++)
		diff.push_back(*(it + 1) - *it);

	size_t	span = *min_element(diff.begin(), diff.end());
	return (span);
}
