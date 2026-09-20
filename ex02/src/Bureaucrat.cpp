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
#include "../include/AForm.hpp"

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

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name)
{
	if (this != &other)
	{
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

void				Bureaucrat::signAForm(AForm& form)
{
	if (form.getState() == true)
	{
		std::cout << this->getName() << " could'nt sign " << form.getName();
		std::cout << " becauce form is already signed" << std::endl;
	}
	else if (form.getMinS() < this->getGrade())
	{
		try
		{
			form.beSigned(*this);
			std::cout << this->getName() << "could'nt sign" << form.getName();
			std::cout << " because the required grade it is : " << form.getMinS() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}
	else
	{
		try
		{
			form.beSigned(*this);
			std::cout << this->getName() << " signed " << form.getName() << std::endl; 
		}
		catch (std::exception &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}
}

void				Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " execute " << form.getName() << std::endl; 
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
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
