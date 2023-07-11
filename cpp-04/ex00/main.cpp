/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <ltalia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:30:06 by ltalia            #+#    #+#             */
/*   Updated: 2022/11/13 12:30:09 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "DogCat.hpp"
#include "Wrong.hpp"

int	main(void)
{
	const Animal		*meta = new Animal();
	const Animal		*j = new Dog("Carnivore");
	const Animal		*i = new Cat();
	const WrongAnimal	*k = new WrongCat();

	i->makeSound();
	j->makeSound();
	k->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;
	delete k;
}
