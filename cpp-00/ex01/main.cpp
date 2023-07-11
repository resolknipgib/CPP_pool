/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <ltalia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:51:40 by ltalia            #+#    #+#             */
/*   Updated: 2022/10/30 17:51:41 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int	check_input(std::string str, int index, int count)
{
	int	i;

	if (str.length() > 1 || str.length() < 1)
		return (1);
	if (!isdigit(str[0]))
		return (1);
	if (count == 8)
	{
		if (str[0] > '8' || str[0] < '1')
			return (1);
		else
			return (0);
	}
	else
	{
		i = std::stoi(str);
		if (i > index || str[0] < '1')
			return (1);
		else
			return (0);
	}
}

int main(void)
{
	PhoneBook	book;
	std::string input;
	std::string c;
	int			i;
	int			j;
	int			x;
	int			count;

	i = 0;
	j = 0;
	x = 0;
	count = 0;
	input = "";
	while (input.compare("EXIT"))
	{
		std::cout << "To add new contact enter \"ADD\".\nTo search for a contact enter \"SEARCH\".\nTo exit the phonebook enter \"EXIT\"" << std::endl;
		std::getline(std::cin, input);
		if (!input.compare("ADD"))
		{
			i = book.add_entry(i);
			if (i > 7)
			{
				i = 0;
				count = 8;
			}
		}
		if (!input.compare("SEARCH"))
		{
			if (i == 0 && count == 0)
				std::cout << "PhoneBook is Empty" << std::endl;
			else
			{
				while (j < i || j < count)
				{
					book.contact_search(j);
					j++;
				}
				while (x > j || x < 1)
				{
					std::cout << "Please Enter the Index Number: " << std::endl;
					std::getline(std::cin, c);
					if (!check_input(c, i, count))
						x = std::stoi(c);
				}
				book.output_details(x - 1);
				x = 0;
				j = 0;
			}
		}
	}
	return (0);
}
