/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DogCat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <ltalia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:01:33 by aperez-b          #+#    #+#             */
/*   Updated: 2022/11/13 12:39:55 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog: public Animal
{
	private:
		Brain		*_brain;
	public:
		Dog(void);
		Dog(Dog const &copy);
		~Dog(void);

		Dog const	&operator=(Dog const &copy);

		std::string const	&getType(void) const;
		Brain 				&getBrain(void) const;
		void				setType(std::string const &type);
		void				setBrain(Brain const &brain);

		void	makeSound(void) const;
};

class Cat: public Animal
{
	private:
		Brain		*_brain;
	public:
		Cat(void);
		Cat(Cat const &copy);
		~Cat(void);

		Cat const	&operator=(Cat const &copy);

		std::string const	&getType(void) const;
		Brain 				&getBrain(void) const;
		void				setType(std::string const &type);
		void				setBrain(Brain const &brain);

		void	makeSound(void) const;
};
