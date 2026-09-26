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
#include "../include/Intern.hpp"

int	main(void)
{
    srand(time(NULL));
	Bureaucrat	Jb = Bureaucrat("Jb", 1);
	Intern		coffeeGuy = Intern();
	AForm*		formOne;
	AForm*		formTwo;
	AForm*		formThree;
	AForm*		formFour;

    std::cout << "--- 1. Testing Creating Forms  ---" << std::endl << std::endl;
	formOne = coffeeGuy.makeForm("presidential pardon", "Santa");
	formTwo = coffeeGuy.makeForm("robotomy request", "Santa");
	formThree = coffeeGuy.makeForm("shrubbery creation", "here");
	formFour = coffeeGuy.makeForm("does not exist", "nowere");

	std::cout << "--- 2. Testing Signing Forms  ---" << std::endl << std::endl;
	Jb.signAForm(*formOne);
	Jb.signAForm(*formTwo);
	Jb.signAForm(*formThree);
	// This will segfault because a ref cannot be NULL
	// Jb.signAForm(*formFour);

	std::cout << "--- 3. Testing Executing Forms  ---" << std::endl << std::endl;
	Jb.executeForm(*formOne);
	Jb.executeForm(*formTwo);
	Jb.executeForm(*formThree);
	// This will segfault because a ref cannot be NULL
	// Jb.executeForm(*formFour);
		
	std::cout << "--- 4. Deleting Forms  ---" << std::endl << std::endl;
	delete formOne;
	delete formTwo;
	delete formThree;
	delete formFour;
	return 0;
}
