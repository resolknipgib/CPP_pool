/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DogCat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <ltalia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:28:36 by ltalia            #+#    #+#             */
/*   Updated: 2022/11/13 12:29:54 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog: public Animal
{
	private:
		std::string	_type;
	public:
		Dog(void);
		Dog(std::string const &type);
		Dog(Dog const &copy);
		~Dog(void);

		Dog const	&operator=(Dog const &copy);

		std::string const	&getType(void) const;
		void				setType(std::string const &type);

		void	makeSound(void) const;
};

class Cat: public Animal
{
	private:
		std::string	_type;
	public:
		Cat(void);
		Cat(std::string const &type);
		Cat(Cat const &copy);
		~Cat(void);

		Cat const	&operator=(Cat const &copy);

		std::string const	&getType(void) const;
		void				setType(std::string const &type);

		void	makeSound(void) const;
};
