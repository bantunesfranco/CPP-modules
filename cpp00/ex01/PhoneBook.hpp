/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: codespace <codespace@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 21:33:50 by codespace     #+#    #+#                 */
/*   Updated: 2023/07/15 20:04:56 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact	contacts[8];
		int		nb_contacts;
		int		get_nb_contacts();
		void	display_details(int index);
		int		simple_display();
	
	public:
		PhoneBook();
		void	add();
		void	search();
		void	exit();
};

#endif
