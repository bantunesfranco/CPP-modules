/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/01 07:59:21 by bfranco       #+#    #+#                 */
/*   Updated: 2023/12/16 22:34:29 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class RPN
{
	private:
		RPN();
		RPN(const RPN& src);
		~RPN();

		RPN&	operator=(const RPN& src);

		static int	_add(int n1, int n2);
		static int	_sub(int n1, int n2);
		static int	_mult(int n1, int n2);
		static int	_div(int n1, int n2);

	public:
		static void	calculate(std::string input);

		class DivideByZeroException : public std::exception
		{
			virtual const char* what() const throw();
		};
};

#endif
