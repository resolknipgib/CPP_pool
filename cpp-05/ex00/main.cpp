/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <ltalia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:49:35 by ltalia            #+#    #+#             */
/*   Updated: 2022/11/15 18:12:44 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	{
		std::cout << "  Constructing  " << std::endl;
		Bureaucrat *a = new Bureaucrat();
		std::cout << std::endl;

		std::cout << "  Testing  " << std::endl;
		std::cout << a;

		try
		{
		a->incrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << " Incrementing grade of " << a->getName() <<
			" failed: " << e.what() << "  " << std::endl;
		}

		std::cout << a;

		try
		{
		a->decrementGrade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "  Decrementing grade of " << a->getName() <<
			" failed: " << e.what() << "  " << std::endl;
		}

		std::cout << a;

		try
		{
		a->decrementGrade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "  Decrementing grade of " << a->getName() <<
			" failed: " << e.what() << "  " << std::endl;
		}

		std::cout << a;
		std::cout << std::endl;

		std::cout << "  Deconstructing  " << std::endl;
		delete a;
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;
		std::cout << "  Constructing  " << std::endl;
		Bureaucrat *a = new Bureaucrat(1);
		std::cout << std::endl;
		std::cout << "  Testing  " << std::endl;
		std::cout << a;

		try
		{
		a->decrementGrade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "  Decrementing grade of " << a->getName() <<
			" failed: " << e.what() << "  " << std::endl;
		}

		std::cout << a;

		try
		{
		a->incrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "  Incrementing grade of " << a->getName() <<
			" failed: " << e.what() << "  " << std::endl;
		}

		std::cout << a;

		try
		{
		a->incrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "  Incrementing grade of " << a->getName() <<
			" failed: " << e.what() << "  " << std::endl;
		}

		std::cout << a;
		std::cout << std::endl;

		std::cout << "  Deconstructing  " << std::endl;
		delete a;
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;
		std::cout << "  Constructing  " << std::endl;
		Bureaucrat *a = NULL;

		try
		{
			a = new Bureaucrat(0);
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "  Constructing default failed: " <<
			e.what() << "  " << std::endl;
		}

		if (a != NULL)
		{
			std::cout << std::endl;

			std::cout << "  Deconstructing b  " << std::endl;
			delete a;
		}

		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;
		std::cout << "  Constructing  " << std::endl;
		Bureaucrat *a = NULL;

		try
		{
			a = new Bureaucrat(160);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "  Constructing default failed: " <<
			e.what() << "  " << std::endl;
		}

		if (a != NULL)
		{
			std::cout << std::endl;
			std::cout << "  Deconstructing b  " << std::endl;
			delete a;
		}
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;
		std::cout << "  Constructing  " << std::endl;
		Bureaucrat *a = new Bureaucrat("Peter", 120);
		std::cout << std::endl;

		std::cout << "  Testing a  " << std::endl;
		std::cout << a;

		a->decrementGrade();

		std::cout << a;
		std::cout << std::endl;

		std::cout << "  Constructing b  " << std::endl;
		Bureaucrat *b = new Bureaucrat(*a);
		std::cout << std::endl;

		std::cout << "  Deconstructing a  " << std::endl;
		delete a;
		std::cout << std::endl;

		std::cout << "  Testing b  " << std::endl;
		std::cout << b;
		b->decrementGrade();
		std::cout << b;
		std::cout << std::endl;

		std::cout << "  Deconstructing b  " << std::endl;
		delete b;

		std::cout << std::endl;
	}
}