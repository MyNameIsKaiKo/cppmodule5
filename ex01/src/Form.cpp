/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 17:11:39 by jleray            #+#    #+#             */
/*   Updated: 2026/09/04 17:11:39 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

Form::Form() : _name("Default"), _isSigned(0), _minSign(1), _minExec(1) {}

Form::Form(std::string name, const int minS, const int minE) : _name(name), _isSigned(0), _minSign(minS), _minExec(minE)
{
	if (minS < 1 || minE < 1)
		throw GradeTooHighException();
	else if (minS > 150 || minE > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _minSign(other._minSign), _minExec(other._minExec) {}

Form&	Form::operator=(const Form& other)
{
	if (this == &other)
		return (*this);
	this->_isSigned = other._isSigned;
	return (*this);
}		

const std::string	Form::getName() const
{
	return (this->_name);
}

bool		 		Form::getState() const
{
	return (this->_isSigned);
}

int					Form::getMinS() const
{
	return (this->_minSign);
}

int					Form::getMinE() const
{
	return (this->_minExec);
}

void				Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > this->_minSign)
		throw GradeTooLowException();
	else
		this->_isSigned = 1;
}

const char*			Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char*			Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream&	operator<<(std::ostream& os, const Form& other)
{
	os << other.getName() << std::endl 
		<< " form state: " << other.getState() << std::endl
		<< " form min required grade for signature: " << other.getMinS() << std::endl
		<< " form min required grade for execution: " << other.getMinE() << std::endl;
	return (os);
}

Form::~Form() {}
