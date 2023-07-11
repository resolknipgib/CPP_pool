/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <ltalia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:45:47 by ltalia            #+#    #+#             */
/*   Updated: 2022/11/15 18:45:49 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "Form.hpp"


class Bureaucrat;

class From;

class ShrubberyCreationForm: public Form
{
	private:
		const std::string _target;

		ShrubberyCreationForm(void);
	public:

		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm &src);

		~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

		void execute(Bureaucrat const &executor)const;

		std::string getTarget(void)const;

};

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm *a);
