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
#include "../include/Form.hpp"

int	main(void)
{
	std::cout << "\n=============================================" << std::endl;
    std::cout << "1. Basic test on the operator \"<<\"" << std::endl;
    std::cout << "=============================================\n" << std::endl;
	try
	{
		Bureaucrat Bob = Bureaucrat("Bob", 150);
		std::cout << Bob << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}	
	try
	{
		Bureaucrat David = Bureaucrat("David", 1);
		std::cout << David << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat Daniel = Bureaucrat("Daniel", 75);
		std::cout << Daniel << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=============================================" << std::endl;
    std::cout << "2.Testing the error on gradeUp and down" << std::endl;
    std::cout << "=============================================\n" << std::endl;
	try
	{
		Bureaucrat Bob = Bureaucrat("Bob", 150);
		Bob.gradeDown();
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}	
	try
	{
		Bureaucrat David = Bureaucrat("David", 1);
		David.gradeUp();
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}	
	try
	{
		Bureaucrat Daniel = Bureaucrat("Daniel", 75);
		std::cout << Daniel << std::endl;
		Daniel.gradeUp();
		std::cout << Daniel << std::endl;
		Daniel.gradeDown();
		std::cout << Daniel << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=============================================" << std::endl;
    std::cout << "3.Testing the throw exeption on constructor" << std::endl;
    std::cout << "=============================================\n" << std::endl;
	try
	{
		Bureaucrat error = Bureaucrat("Error", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat error = Bureaucrat("Error", 151);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=============================================" << std::endl;
    std::cout << "4. Testing Form constructors and exceptions" << std::endl;
    std::cout << "=============================================\n" << std::endl;
    try
    {
        Form validForm = Form("Standard Form", 50, 100);
        std::cout << validForm << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    try
    {
        Form errorHigh = Form("Top Secret Form", 0, 50);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught (Sign grade too high): " << e.what() << std::endl;
    }
    try
    {
        Form errorLow = Form("Trash Form", 50, 151);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught (Exec grade too low): " << e.what() << std::endl;
    }

    std::cout << "\n=============================================" << std::endl;
    std::cout << "5. Testing Form signing (beSigned & signForm)" << std::endl;
    std::cout << "=============================================\n" << std::endl;
    try
    {
        Bureaucrat boss = Bureaucrat("The Boss", 1);
        Bureaucrat intern = Bureaucrat("The Intern", 149);

        Form taxForm = Form("Tax Form 1040", 50, 50);
        Form ndaForm = Form("NDA", 1, 1);

        std::cout << taxForm << std::endl;
        std::cout << ndaForm << std::endl;

        std::cout << "\n--- Intern tries to sign ---" << std::endl;
        intern.signForm(taxForm);
        intern.signForm(ndaForm);

        std::cout << "\n--- Boss tries to sign ---" << std::endl;
        boss.signForm(taxForm);
        boss.signForm(ndaForm);

        std::cout << "\n--- Status after signing attempts ---" << std::endl;
        std::cout << taxForm << std::endl;
        std::cout << ndaForm << std::endl;

        std::cout << "\n--- Attempting to sign already signed form ---" << std::endl;
        boss.signForm(taxForm);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
	return (0);
}
