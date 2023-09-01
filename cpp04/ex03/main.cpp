/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 14:26:21 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/01 17:47:11 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(void) 
{
	// subject

	MateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	Character* mage = new Character("Mage");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	mage->equip(tmp);
	tmp = src->createMateria("cure");
	mage->equip(tmp);

	ICharacter* wizard = new Character("Wizard");
	mage->use(0, *wizard);
	mage->use(1, *wizard);

	// deep copy MateriaSource
	MateriaSource* src2 = new MateriaSource();
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());
	MateriaSource* src_copy = new MateriaSource(*src2);
	delete src2;

	// full inventory and unequip
	tmp = src_copy->createMateria("ice");
	mage->equip(tmp);

	AMateria *last_item = src_copy->createMateria("cure");
	mage->equip(last_item);

	mage->equip(tmp);

	mage->unequip(3);

	delete last_item;

	// deep copy Character
	Character* mage_copy = new Character(*mage);
	delete mage;

	mage_copy->use(0, *wizard);
	mage_copy->use(1, *wizard);
	// empty
	mage_copy->use(3, *wizard);

	// materia that does not exist
	tmp = src->createMateria("invalid");
	tmp = src->createMateria("ice");

	mage_copy->equip(tmp);
	mage_copy->use(3, *wizard);

	// delete objects
	delete wizard;
	delete mage_copy;
	delete src;
	delete src_copy;
	return (0);
}
