/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <ltalia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:26:34 by ltalia            #+#    #+#             */
/*   Updated: 2022/11/13 12:26:39 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): _type("undefined")
{
	std::cout << "Animal " << this->_type << " created with default constructor." << std::endl;
}

Animal::Animal(std::string const &type): _type(type)
{
	std::cout << "Animal " << this->_type << " created." << std::endl;
}

Animal::Animal(Animal const &copy)
{
	*this = copy;
	std::cout << "Animal " << this->_type << " copied." << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal " << this->_type << " destroyed." << std::endl;
}

Animal const	&Animal::operator=(Animal const &copy)
{
	std::cout << "Assignment operator for Animal " << this->_type << " called." << std::endl;
	this->_type = copy.getType();
	return (*this);
}

std::string const	&Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::setType(const std::string &type)
{
	this->_type = type;
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal " << this->_type << " made a sound!" << std::endl;
}
