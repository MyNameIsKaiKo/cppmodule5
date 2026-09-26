/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 14:26:00 by jleray            #+#    #+#             */
/*   Updated: 2026/09/26 14:26:00 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
	if (this != &other)
		*this = other;
}

Intern&	Intern::operator=(const Intern& other)
{
	if (this == &other)
		return (*this);
	*this = other;
	return (*this);
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	AForm*		form;
	int			i = 0;
	std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	while (i < 3)
	{
		if (name == forms[i])
			break;
		i++;
	}
	switch (i)
	{
		case 0:
			form = new PresidentialPardonForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new ShrubberyCreationForm(target);
			break;
		default:
			std::cout << "\"" << name << "\"" << " is not a valid form" << std::endl;
			form = NULL;
	}
	if (form != NULL)
		std::cout << "Intern creates " << "<" << name << ">" << std::endl;
	return (form);
}

Intern::~Intern() {}
