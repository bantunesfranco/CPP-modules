/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/16 12:29:37 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/17 12:11:24 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int	main()
{
	ScavTrap	bob("bob");
	ScavTrap	joe(bob);

	std::cout << "\nBob: " << "hp = " << bob.getHitPts() << " atk = " \
	<< bob.getAtkDmg() << " energy = " << bob.getEnergy() << std::endl;
	bob.attack("target");
	std::cout << "" << std::endl;

	joe.setName("joe");
	bob.setAtkDmg(2);
	bob.setEnergy(2);
	
	for (int i = 0; i < 4; i++)
	{
		bob.attack("joe");
		joe.takeDamage(bob.getAtkDmg());
	}
	std::cout << "" << std::endl;
	
	bob.takeDamage(20);
	bob.beRepaired(5);
	std::cout << "" << std::endl;

	for (int i = 0; i < 7; i++)
		joe.beRepaired(2);
	std::cout << "" << std::endl;

	joe.setHitPts(2);
	joe.setEnergy(0);
	joe.beRepaired(2);
	std::cout << "" << std::endl;

	bob.guardGate();
	joe.guardGate();
	std::cout << "" << std::endl;

	return (0);
}
