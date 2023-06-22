/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/16 12:29:37 by bfranco       #+#    #+#                 */
/*   Updated: 2023/06/22 09:51:24 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int	main()
{
	ScavTrap	bob("bob");

	bob.attack("target");
	bob.setHitPts(20);
	bob.takeDamage(5);
	bob.beRepaired(5);
	 
	ScavTrap	joe(bob);

	joe.setName("joe");

	joe.setEnergy(100);
	joe.setHitPts(110);
	bob.setAtkDmg(20);
	bob.setEnergy(100);

	std::cout << "" << std::endl;
	
	for (int i = 0; i < 4; i++)
	{
		bob.attack("joe");
		joe.takeDamage(bob.getAtkDmg());
	}

	std::cout << "" << std::endl;

	joe.setAtkDmg(10);
	joe.attack("bob");
	bob.takeDamage(joe.getAtkDmg());
	bob.beRepaired(5);
	bob.beRepaired(10);
	bob.beRepaired(100);

	bob.guardGate();
	joe.guardGate();

	std::cout << "" << std::endl;

	return (0);
}