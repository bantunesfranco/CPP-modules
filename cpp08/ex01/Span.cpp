/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/29 14:35:01 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/29 15:31:52 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

const char* Span::CannotAddElementException::what() const
{
	return "Cannot Add Element: Span is full";
}
const char* Span::NoSpanFoundException::what() const
{
	return "No Span Found";
}

const char* Span::NotEnoughElementsException::what() const
{
	return "Not Enough Elements in Span";
}

Span::Span(void) : _nbElems(0)
{
	std::cout << "Default constructor" << std::endl;
}

Span::Span(unsigned int N) : _nbElems(0)
{
	std::cout << "Default constructor" << std::endl;
}

Span::Span(const Span& src) : _nbElems(src._nbElems)
{
	std::cout << "Copy constructor" << std::endl;
}

Span::~Span(void)
{
	std::cout << "Default destructor" << std::endl;
}

void	Span::addNumber(int i)
{
	if (this->_nbElems < "size member from container" - 1)
		"container add int";
	else
		throw(CannotAddElementException());
}

void	Span::fillSpan()
{
	//something range interator
}

size_t	Span::longestSpan(void)
{
	size_t	span = 0;
	if (this->_nbElems < 2)
		throw(NotEnoughElementsException());
	//some iterator
	for (it; (it + 1) != end(); it++)
	{
		size_t diff = abs((*it + 1) - *it);
		if (diff > span)
			span = diff;
	}
	if (span == 0)
		throw(NoSpanFoundException());
	return (span);
}

size_t	Span::shortestSpan(void)
{
	size_t	span = 0;
	if (this->_nbElems < 2)
		throw(NotEnoughElementsException());
	//some iterator
	for (it; (it + 1) != end(); it++)
	{
		size_t diff = abs((*it + 1) - *it);
		if (diff < span && diff != 0)
			span = diff;
	}
	if (span == 0)
		throw(NoSpanFoundException());
	return (span);
}
