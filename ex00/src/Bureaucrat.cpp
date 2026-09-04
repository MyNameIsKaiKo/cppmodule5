/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 17:45:48 by jleray            #+#    #+#             */
/*   Updated: 2026/08/19 17:45:48 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if (grade > 150)
	{
		throw GradeTooLowException();
	}
	if (grade < 1)
	{
		throw GradeTooHighException();
	}
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	if (this != &other)
	{
		(std::string)this->_name = other._name;
		this->_grade = other._grade;
	}
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this == &other)
		return (*this);
	this->_grade = other._grade;
	return (*this);
}


const std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int					Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void				Bureaucrat::gradeUp()
{
	try
	{
		if (this->_grade != 1)
			this->_grade -= 1;
		else
			throw (1);
 	}
	catch (int error)
	{
		std::cout << "grade is already at maximum" << std::endl;
	}
}

void				Bureaucrat::gradeDown()
{
	try
	{
		if (this->_grade != 150)
			this->_grade += 1;
		else
			throw(1);
	}
	catch (int error)
	{
		std::cout << "grade is already at minimum" << std::endl;
	}
}

const char*			Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char*			Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

Bureaucrat::~Bureaucrat() {}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& other)
{
	os << other.getName() << ", Bureaucrat grade " << other.getGrade() << ".";
	return (os);
}
