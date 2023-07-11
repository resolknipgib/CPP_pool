/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <ltalia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:16:41 by ltalia            #+#    #+#             */
/*   Updated: 2022/11/10 16:16:42 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "A wild Harl has appeared!" << std::endl;
}

Harl::~Harl(void)
{
	std::cout << "Wild Harl flew away!" << std::endl;
}

void	Harl::debug(void)
{
	std::cout << MAGENTA << "[DEBUG]   " << DEFAULT;
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger.";
	std::cout << " I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << GRAY << "[INFO]    " << DEFAULT;
	std::cout << "I cannot believe adding extra bacon costs more money.";
	std::cout << " You didn’t put\n"
                 "enough bacon in my burger!";
	std::cout << " If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << YELLOW << "[WARNING] " << DEFAULT;
	std::cout << "I think I deserve to have some extra bacon for free."
                 "I’ve been coming for\n"
                 "years whereas you started working here since last month."
                 "working here last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << RED << "[ERROR]   " << DEFAULT;
	std::cout << "This is unacceptable, I want to speak to the manager now.";
	std::cout << std::endl;
}

void	Harl::complain(std::string level)
{
	void		(Harl::*ptr_complain[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*ptr_complain[i])();
			break ;
		}
	}
}
