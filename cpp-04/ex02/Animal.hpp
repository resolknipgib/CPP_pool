/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <ltalia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:38:43 by ltalia            #+#    #+#             */
/*   Updated: 2022/11/13 12:38:52 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Brain.hpp"

class Animal
{
	protected:
		Animal(void);
		Animal(std::string const &type);
		Animal(Animal const &copy);
		std::string	_type;
	public:
		virtual ~Animal(void);

		Animal const	&operator=(Animal const &copy);

		std::string const	&getType(void) const;
		void				setType(std::string const &type);
		virtual Brain 		&getBrain(void) const = 0;

		virtual void	makeSound(void) const;
};
