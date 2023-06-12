/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/11 17:06:25 by bfranco       #+#    #+#                 */
/*   Updated: 2023/06/12 19:55:17 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	Harl		*bob = new Harl();
	int			i = 0;

	if (argc != 2)
	{	
		std::cerr << "Invalid number of arguments" << std::endl;
		return (1);
	}

	while (i < 4)
	{
		if (!levels[i].compare(argv[1]))
			break ;
		i++;
	}
	
	switch (i)
	{
		case 0 :
			for (int j = i; j < 4; j++)
				bob->complain(levels[j]);
			break ;
		case 1 :
			for (int j = i; j < 4; j++)
				bob->complain(levels[j]);
			break ;
		case 2 :
			for (int j = i; j < 4; j++)
				bob->complain(levels[j]);
			break ;
		case 3 :
			for (int j = i; j < 4; j++)
				bob->complain(levels[j]);
			break ;
		default :
			std::cout << "[ Bla bla bla, probably something irrelevant ]" << std::endl;
			break ;
	}
	
	delete bob;
	return (0);
}