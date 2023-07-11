/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <ltalia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:52:06 by ltalia            #+#    #+#             */
/*   Updated: 2022/10/30 17:52:07 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact details[8];

	public:
		int			add_entry(int index);
		void		contact_search(int index);
		std::string	format_contact(std::string str);
		void		output_details(int i);
		PhoneBook(void);
		~PhoneBook(void);
};

#endif
