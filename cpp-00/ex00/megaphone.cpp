/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <ltalia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:50:59 by ltalia            #+#    #+#             */
/*   Updated: 2022/10/30 17:51:10 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (argc > 1 && argv && argv[i])
	{
		j = 0;
		while (i > 0 && argv[i][j])
		{
			std::cout << (char)std::toupper(argv[j][i]);
			j++;
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
}
