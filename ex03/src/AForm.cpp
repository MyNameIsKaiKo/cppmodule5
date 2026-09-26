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

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _minSign(1), _minExec(1) {}

AForm::AForm(std::string name, const int minS, const int minE) : _name(name), _isSigned(false), _minSign(minS), _minExec(minE)
{
	if (minS < 1 || minE < 1)
		throw GradeTooHighException();
	else if (minS > 150 || minE > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _minSign(other._minSign), _minExec(other._minExec) {}

AForm&	AForm::operator=(const AForm& other)
{
	if (this == &other)
		return (*this);
	this->_isSigned = other._isSigned;
	return (*this);
}		

const std::string	AForm::getName() const
{
	return (this->_name);
}

bool		 		AForm::getState() const
{
	return (this->_isSigned);
}

int					AForm::getMinS() const
{
	return (this->_minSign);
}

int					AForm::getMinE() const
{
	return (this->_minExec);
}

void				AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > this->_minSign)
		throw GradeTooLowException();
	else
		this->_isSigned = true;
}

void				AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->_minExec)
		throw GradeTooLowException();
	if (!this->_isSigned)
		throw FormNotSignedException();
	this->executeAction();
}
		
const char*			AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char*			AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char*			AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

std::ostream&	operator<<(std::ostream& os, const AForm& other)
{
	os << other.getName() << std::endl 
		<< " form state: " << other.getState() << std::endl
		<< " form min required grade for signature: " << other.getMinS() << std::endl
		<< " form min required grade for execution: " << other.getMinE() << std::endl;
	return (os);
}

AForm::~AForm() {}
