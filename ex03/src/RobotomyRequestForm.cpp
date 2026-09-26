/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotmyRequestForm.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 01:46:18 by jleray            #+#    #+#             */
/*   Updated: 2026/09/20 01:46:18 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45), _target("default")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target)
{}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

void					RobotomyRequestForm::executeAction() const
{
	std::cout << "*Drilling noises...*" << std::endl;
	std::cout << "*More Drilling noises...*" << std::endl;
	if (rand() % 2)
		std::cout << "robotomy has failed" << std::endl;
	else
		std::cout << this->_target << " has been robotomized" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {}
