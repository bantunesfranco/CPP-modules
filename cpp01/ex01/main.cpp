/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/10 18:11:50 by bfranco       #+#    #+#                 */
/*   Updated: 2023/06/10 20:35:40 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

int	main()
{
	Zombie* horde = zombieHorde(20, "Bob");
	for (int i = 0; i < 20; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}