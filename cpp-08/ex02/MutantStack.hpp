/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <ltalia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:26:13 by ltalia            #+#    #+#             */
/*   Updated: 2022/11/16 16:26:49 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
public:
	typedef std::stack<T> stack;
	typedef typename stack::container_type container;
	typedef typename container::iterator iterator;

	MutantStack() : stack()
	{
		std::cout << "Default Constructor called" << std::endl;
	}

	MutantStack(const stack &src) : stack(src)
	{
		std::cout << "Copy Constructor called" << std::endl;
	}

	~MutantStack()
	{
		std::cout << "Deconstuctor called" << std::endl;
	}

	stack &operator=(const stack &src)
	{
		if (*this != src)
			*this = src;
		return (*this);
	}

	iterator begin()
	{
		return (stack::c.begin());
	}

	iterator end()
	{
		return (stack::c.end());
	}
};
