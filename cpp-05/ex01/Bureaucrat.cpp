/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <ltalia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:14:09 by ltalia            #+#    #+#             */
/*   Updated: 2022/11/15 18:16:42 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void): _name("default"), _grade(150)
{
	std::cout << "Bureaucrat Default Constructor called for " << this->getName() <<
	" with grade of " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src.getName() + "_copy")
{
	std::cout << "Bureaucrat Copy Constructor called to copy " << src.getName() <<
	" into " << this->getName() << std::endl;
	*this = src;
}

Bureaucrat::Bureaucrat(int grade): _name("default")
{
	std::cout << "Bureaucrat Constructor called for " << this->getName() <<
	" with grade of " << grade << std::endl;
	try
	{
		this->setGrade(grade);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << " Constructing " << this->getName() <<
		" failed: " << e.what() << std::endl <<
		"Grade now set to 1" << "  " << std::endl;
		this->setGrade(1);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << " Constructing " << this->getName() <<
		" failed: " << e.what() << std::endl <<
		"Grade now set to 150" << "  " << std::endl;
		this->setGrade(150);
	}
}

Bureaucrat::Bureaucrat(const std::string name): _name(name), _grade(150)
{
	std::cout << "Bureaucrat Constructor called for " << this->getName() <<
	" with grade of " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
	std::cout << "Bureaucrat Constructor called for " << this->getName() <<
	" with grade of " << grade << std::endl;
	try
	{
		this->setGrade(grade);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << " Constructing " << this->getName() <<
		" failed: " << e.what() << std::endl <<
		"Grade now set to 1" << "  " << std::endl;
		this->setGrade(1);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << " Constructing " << this->getName() <<
		" failed: " << e.what() << std::endl <<
		"Grade now set to 150" << "  " << std::endl;
		this->setGrade(150);
	}

}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Deconstructor for " << this->getName() << " called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << "Bureaucrat Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	this->_grade = src.getGrade();
	return *this;
}

void	Bureaucrat::incrementGrade(void)
{
	try
	{
		std::cout << "Trying to increment grade of " << this->getName() << std::endl;
		this->setGrade(this->_grade - 1);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << " Incrementing grade of " << this->getName() <<
		" failed: " << e.what() << "  " << std::endl;
	}
}

void	Bureaucrat::decrementGrade(void)
{
	try
	{
		std::cout << "Trying to decrement grade of " << this->getName() << std::endl;
		this->setGrade(this->_grade + 1);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << " Decrementing grade of " << this->getName() <<
		" failed: " << e.what() << "  " << std::endl;
	}
}

void	Bureaucrat::signForm(Form &form)
{
	form.beSigned(*this);
}

const std::string	Bureaucrat::getName(void)const
{
	return (this->_name);
}

size_t	Bureaucrat::getGrade(void)const
{
	return (this->_grade);
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
	o << "Bureaucrat " << a->getName() << ":\n\tgrade: " << a->getGrade() << std::endl;
	return (o);
}
