/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <ltalia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:26:47 by ltalia            #+#    #+#             */
/*   Updated: 2022/11/13 12:27:18 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal
{
	protected:
		std::string	_type;
	public:
		Animal(void);
		Animal(std::string const &type);
		Animal(Animal const &copy);
		virtual ~Animal(void);

		Animal const	&operator=(Animal const &copy);

		std::string const	&getType(void) const;
		void				setType(std::string const &type);

		virtual void	makeSound(void) const;
};
