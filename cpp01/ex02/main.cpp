/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/10 20:47:27 by bfranco       #+#    #+#                 */
/*   Updated: 2023/06/15 18:54:58 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string &ref = str;

	std::cout << "memory address of str: " << &str << " and value of str: " << str << std::endl;
	std::cout << "memory address held by ptr: " << ptr << " and value pointed by ptr: " << *ptr << std::endl;
	std::cout << "memory address held by ref: " << &ref << " and value pointed by ref: " << ref << std::endl;
}
