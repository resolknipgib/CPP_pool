/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <ltalia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:14:04 by ltalia            #+#    #+#             */
/*   Updated: 2022/11/16 13:43:21 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <stdint.h>

typedef struct Data
{
	std::string	name;
	size_t		age;
	Data		*next;
}				Data;

class Serializer
{
	private:

	public:
		Serializer();
		Serializer(const Serializer &src);

		~Serializer();

		Serializer &operator=(const Serializer &src);

		uintptr_t serialize(Data *ptr);
		Data *unserialize(uintptr_t raw);


};

// Ostream overload
// std::ostream	&operator<<(std::ostream &o, Data *a);
