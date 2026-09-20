/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 15:40:09 by jleray            #+#    #+#             */
/*   Updated: 2026/08/21 15:40:09 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"

int	main(void)
{
    srand(time(NULL));
	Bureaucrat	Bob = Bureaucrat("Bob", 145);
	Bureaucrat	David = Bureaucrat("David", 72);
	Bureaucrat	Jb = Bureaucrat("Jb", 1);

    std::cout << "--- 1. Testing ShrubberyCreationForm  ---" << std::endl;
	
	ShrubberyCreationForm tree = ShrubberyCreationForm("garden");
	Bob.signAForm(tree);
	David.signAForm(tree);

	Bob.executeForm(tree);
	David.executeForm(tree);

	std::cout << "A file has been created." << std::endl;

	ShrubberyCreationForm notTree = ShrubberyCreationForm("garden");
	David.executeForm(notTree);

	std::cout << "--- 2. Testing RobotomyRequestForm  ---" << std::endl;

	RobotomyRequestForm tryOne = RobotomyRequestForm("Dummy One");
	RobotomyRequestForm tryTwo = RobotomyRequestForm("Dummy Two");
	RobotomyRequestForm tryThree = RobotomyRequestForm("Dummy Three");
	RobotomyRequestForm tryFour = RobotomyRequestForm("Dummy Four");
	RobotomyRequestForm tryFive = RobotomyRequestForm("Dummy Five");

	Jb.signAForm(tryOne);
	Jb.signAForm(tryTwo);
	Jb.signAForm(tryThree);
	Jb.signAForm(tryFour);

	Jb.executeForm(tryOne);
	Jb.executeForm(tryTwo);
	Jb.executeForm(tryThree);
	Jb.executeForm(tryFour);
	Jb.executeForm(tryFive);

	std::cout << "--- 3. Testing PresidentialPardonForn ---" << std::endl;

	PresidentialPardonForm pardon = PresidentialPardonForm("Bobito");

	Bob.signAForm(pardon);
	Jb.executeForm(pardon);
	Jb.signAForm(pardon);
	Bob.executeForm(pardon);
	Jb.executeForm(pardon);
    return 0;
}
