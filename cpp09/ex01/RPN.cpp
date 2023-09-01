/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/01 07:59:18 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/01 12:57:34 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "sstream"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const RPN& src)
{
	(void)src;
	return ;
}

RPN &RPN::operator=(const RPN& src)
{
	(void)src;
	return (*this);
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
		exit(1);
	}
}



void	RPN::calculate(std::string input)
{
	std::istringstream	ss(input);
	std::stack<int>		values;
	std::stack<int>		temp;
	std::string			operators = "+-*/";
	std::string			token;
	
	int	(*fptr[4])(int n1, int n2) = {&RPN::_add, &RPN::_sub, &RPN::_mult, &RPN::_div};

	while (std::getline(ss, token, ' '))
	{
		if (token.length() != 1 || operators.find(input[input.size() - 1]) == std::string::npos)
		{
			std::cerr << "Error: Invalid input" << std::endl;
			exit(1) ;
		}
		else if (operators.find(token[0]) != std::string::npos)
		{
			if (values.size() < 2)
			{
				if (values.size() == 1 && temp.size() > 0)
				{
					int n1 = values.top();
					values.pop();
					values.push(temp.top());
					temp.pop();
					values.push(n1);
				}
				else
				{
					std::cerr << "Error: Invalid input" << std::endl;
					exit(1) ;
				}
			}
			int n2 = values.top();
			values.pop();
			int n1 = values.top();
			values.pop();
			values.push(fptr[operators.find(token[0])](n1, n2));
			std::cout << n1 << " " + token + " " << n2 << " = " << values.top() << std::endl;
		}
		else if (isdigit(token[0]))
		{
			values.push(static_cast<int>(token[0] - '0'));
		}
		else
		{
			std::cerr << "Error: Invalid input" << std::endl;
			exit(1) ;
		}
	}
	std::cout << values.top() << std::endl;
}
