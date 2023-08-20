/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MateriaSource.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/20 12:10:42 by bfranco       #+#    #+#                 */
/*   Updated: 2023/08/20 13:37:36 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource
{
	private:
		AMateria*	_materia[4];
		int			_count;

	public:
		MateriaSource();
		MateriaSource(MateriaSource const& src);
		~MateriaSource();

		MateriaSource&	operator=(MateriaSource const& src);

		void			learnMateria(AMateria*);
		AMateria*		createMateria(std::string const & type);
};

#endif