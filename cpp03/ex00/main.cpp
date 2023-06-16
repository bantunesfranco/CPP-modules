/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/16 12:29:37 by bfranco       #+#    #+#                 */
/*   Updated: 2023/06/16 12:34:58 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int	main()
{
	ClapTrap	bob("bob");

	bob.attack("target");
	bob.takeDamage(5);
	bob.beRepaired(5);

	bob.setName("joe");
	 
	ClapTrap	joe(bob);

	std::cout << joe.getName() << std::endl;
	joe.setEnergy(100);
	joe.setHitPts(100);
	for (int i = 0; i < 10; i++)
	{
		bob.attack("joe");
		joe.takeDamage(bob.getAtkDmg());
	}
	joe.attack("bob");
	bob.takeDamage(joe.getAtkDmg());
	bob.beRepaired(10);
	bob.beRepaired(100);

	return (0);
}