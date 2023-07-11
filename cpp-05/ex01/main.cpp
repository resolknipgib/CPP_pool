/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <ltalia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:30:36 by tblaase           #+#    #+#             */
/*   Updated: 2022/11/15 18:20:39 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	{
		std::cout << " Constructing  " << std::endl;
		Bureaucrat *a = new Bureaucrat();
		Form *b = new Form();
		std::cout << std::endl;

		std::cout << " Testing  " << std::endl;
		std::cout << a;
		std::cout << b;

		try
		{
			b->beSigned(*a);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << a->getName() << " was not able to sign " << b->getName() << ": " << e.what() << std::endl;
		}

		std::cout << b;
		std::cout << std::endl;

		std::cout << " Deconstructing  " << std::endl;
		delete a;
		delete b;
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << " Constructing  " << std::endl;
		Bureaucrat *a = new Bureaucrat("Assistant", 145);
		Bureaucrat *b = new Bureaucrat("CEO", 1);
		Form *c = new Form("Rent Contract", 140, 100);
		std::cout << std::endl;

		std::cout << " Testing  " << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << c;

		try
		{
			a->signForm(*c);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << " " << a->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << "  " << std::endl;
		}

		std::cout << c;
		try
		{
			c->beSigned(*b);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << " " << b->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << "  " << std::endl;
		}
		std::cout << c;

		b->signForm(*c);
		std::cout << std::endl;

		std::cout << " Deconstructing  " << std::endl;
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << " Constructing  " << std::endl;
		Form *a = NULL;

		try
		{
			a = new Form(160, 145);
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cerr << " Constructing default failed: " <<
			e.what() << "  " << std::endl;
		}

		try
		{
			a = new Form(145, 160);
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cerr << " Constructing default failed: " <<
			e.what() << "  " << std::endl;
		}

		try
		{
			a = new Form(-15, 145);
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cerr << " Constructing default failed: " <<
			e.what() << "  " << std::endl;
		}

		try
		{
			a = new Form(145, -15);
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cerr << " Constructing default failed: " <<
			e.what() << "  " << std::endl;
		}

		if (a != NULL)
		{
			std::cout << std::endl;
			std::cout << " Deconstructing  " << std::endl;
			delete a;
		}
		std::cout << std::endl;
	}
	return (0);
}
