/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <ltalia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:40:24 by ltalia            #+#    #+#             */
/*   Updated: 2022/11/15 18:41:40 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	{
		std::cout << "  Constructing  " << std::endl;
		Bureaucrat *a = new Bureaucrat();
		Intern *z = new Intern();
		Form *b = z->makeForm("SomeRandomForm", "Clown");
		b = z->makeForm("PresidentialPardonForm", "Clown");
		std::cout << std::endl;

		std::cout << "  Testing  " << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << std::endl;

		try
		{
			b->beSigned(*a);

		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << " " << a->getName() << " was not able to sign " << b->getName() << ": " << e.what() << "  " << std::endl;
		}

		std::cout << std::endl;
		std::cout << b;
		std::cout << std::endl;

		std::cout << "  Deconstructing  " << std::endl;
		delete a;
		delete b;
		delete z;
		std::cout << std::endl;
	}
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "  Constructing  " << std::endl;
		Bureaucrat *a = new Bureaucrat("Assistant", 145);
		Bureaucrat *b = new Bureaucrat("CEO", 1);
		Form *c = new PresidentialPardonForm("some dude");
		std::cout << std::endl;

		std::cout << "  Testing  " << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << c;
		std::cout << std::endl;

		try
		{
			c->execute(*b);
		}
		catch (Form::FormNotSignedException &e)
		{
			std::cerr << " " << a->getName() << " was not able to execute the Form " << c->getName() << ": " << e.what() << "  " << std::endl;
		}
		std::cout << std::endl;
		try
		{
			c->beSigned(*a);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << " " << a->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << "  " << std::endl;
		}

		std::cout << std::endl;
		std::cout << c;
		std::cout << std::endl;
		try
		{
			c->beSigned(*b);
		}

		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << " " << b->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << "  " << std::endl;
		}
		std::cout << std::endl;
		std::cout << c;
		std::cout << std::endl;

		std::cout << std::endl;
		b->signForm(*c);
		std::cout << std::endl;

		try
		{
			c->execute(*a);

		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << " " << a->getName() << " was not able to execute the Form " << c->getName() << ": " << e.what() << "  " << std::endl;
		}
		std::cout << std::endl;

		try
		{
			c->execute(*b);

		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << " " << b->getName() << " was not able to execute the Form " << c->getName() << ": " << e.what() << "  " << std::endl;
		}
		std::cout << std::endl;

		std::cout << "  Deconstructing  " << std::endl;
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "  Constructing  " << std::endl;
		Bureaucrat *a = new Bureaucrat("Emperor", 1);
		Intern *z = new Intern();
		Form *b = z->makeForm("RobotomyRequestForm", "Bender");
		Form *c = z->makeForm("ShrubberyCreationForm", "Cristmas");
		std::cout << std::endl;

		std::cout << "  Testing  " << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << c;
		std::cout << std::endl;

		b->beSigned(*a);
		a->signForm(*c);
		std::cout << std::endl;
		std::cout << b;
		std::cout << c;
		std::cout << std::endl;

		for (int i= 0; i < 10; i++)
			b->execute(*a);
		a->executeForm(*c);

		std::cout << std::endl;

		std::cout << "  Deconstructing  " << std::endl;
		delete a;
		delete b;
		delete c;
		delete z;
		std::cout << std::endl;
	}
	return (0);
}
