/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MateriaSource.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/20 12:10:42 by bfranco       #+#    #+#                 */
/*   Updated: 2023/09/04 12:27:52 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*	_materia[4];
		int			_count;

	public:
		MateriaSource();
		MateriaSource(MateriaSource const& src);
		virtual ~MateriaSource();

		MateriaSource&	operator=(MateriaSource const& src);

		void			learnMateria(AMateria*);
		AMateria*		createMateria(std::string const & type);
};

#endif
