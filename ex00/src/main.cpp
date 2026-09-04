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
	return (0);
}
