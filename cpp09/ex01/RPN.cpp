/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/01 07:59:18 by bfranco       #+#    #+#                 */
/*   Updated: 2024/01/04 19:17:57 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <cstdlib>

const char* RPN::DivideByZeroException::what() const throw()
{
	return ("Error: Division by zero");
}

int	RPN::_add(int n1, int n2)
{
	return (n1 + n2);
}

int	RPN::_sub(int n1, int n2)
{
	return (n1 - n2);
}

int	RPN::_mult(int n1, int n2)
{
	return (n1 * n2);
}

int	RPN::_div(int n1, int n2)
{
	try
	{
		if (n2 == 0)
			throw (RPN::DivideByZeroException());
		return (n1 / n2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

static void	exit_error()
{
	std::cerr << "Error: Invalid input" << std::endl;
	std::exit(EXIT_FAILURE);
}

void	RPN::calculate(std::string input)
{
	std::istringstream	ss(input);
	std::stack<int>		values;
	std::stack<int>		temp;
	std::string			operators = "+-*/";
	std::string			token;
	
	int	(*fptr[4])(int n1, int n2) = {&RPN::_add, &RPN::_sub, &RPN::_mult, &RPN::_div};

	input.erase(0, input.find_first_not_of(" \t\n\r\f\v"));
	input.erase(input.find_last_not_of(" \t\n\r\f\v") + 1);

	if (input.empty())
		exit_error();
	else if (input.size() == 1)
	{
		if (!isdigit(input[0]))
			exit_error();
		std::cout << input << std::endl;
		std::exit(EXIT_SUCCESS);
	}

	while (std::getline(ss, token, ' '))
	{

		if (token.length() != 1 || operators.find(input[input.size() - 1]) == std::string::npos)
			exit_error();
		else if (operators.find(token[0]) != std::string::npos)
		{
			if (values.size() < 2)
				exit_error();
			int n2 = values.top();
			values.pop();
			int n1 = values.top();
			values.pop();
			values.push(fptr[operators.find(token[0])](n1, n2));
		}
		else if (isdigit(token[0]))
			values.push(static_cast<int>(token[0] - '0'));
		else
			exit_error();
	}
	if (values.size() != 1)
		exit_error();
	std::cout << values.top() << std::endl;
}
