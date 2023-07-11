/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <ltalia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:19:46 by ltalia            #+#    #+#             */
/*   Updated: 2022/11/16 16:19:58 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iterator>
#include <iostream>
#include <exception>

class NotFoundException: public std::exception
{
	public:
			virtual const char *what() const throw()
			{
				return ("Not found");
			}
};

template< typename T>
typename T::iterator easyfind(T &in, int i)
{
	typename T::iterator	it;
	it = find(in.begin(), in.end(), i);
	if (it == in.end())
	{
		throw (NotFoundException());
	}
	return (it);
}
