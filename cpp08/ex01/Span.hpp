/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/29 14:34:58 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/29 17:16:58 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>


class Span
{
	private:
		unsigned int		_N;
		std::vector<int>	_vec;

	public:

		class NotEnoughElementsException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class CannotAddElementException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		
		Span();
		Span(unsigned int N);
		Span(Span const &src);
		~Span(void);

		Span &operator=(Span const &src);

		void	addNumber(int i);
		void	fillSpan(int i, int j);
		size_t	shortestSpan(void);
		size_t	longestSpan(void);
	

};

#endif
