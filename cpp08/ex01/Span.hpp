/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/29 14:34:58 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/29 15:31:18 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <array>
#include <vector>
#include <algorithm>

// template <unsigned size>
class Span
{
	class NotEnoughElementsException : std::exception
	{
		virtual const char* what() const throw();
	};
	
	class NoSpanFoundException : std::exception
	{
		virtual const char* what() const throw();
	};

	class CannotAddElementException : std::exception
	{
		virtual const char* what() const throw();
	};

	public:
		Span();
		Span(unsigned int N);
		Span(Span const &src);
		~Span(void);

		Span &operator=(Span const &src);

		void	addNumber(int i);
		void	fillSpan();
		size_t	shortestSpan(void);
		size_t	longestSpan(void);
	
	private:
		unsigned int	_nbElems;

};

#endif
