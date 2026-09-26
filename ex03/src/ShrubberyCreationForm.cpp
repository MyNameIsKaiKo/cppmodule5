/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 01:11:33 by jleray            #+#    #+#             */
/*   Updated: 2026/09/20 01:11:33 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137), _target("default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target)
{}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

void					ShrubberyCreationForm::executeAction() const
{
	std::string 	out;
	std::ofstream	outFile;

	out = this->_target;
	out += "_shrubbery";
	outFile.open(out.c_str());
	if (!outFile.is_open())
	{
		std::cerr << "Error: Could not create output file" << std::endl;
		return ;
	}
	outFile << "      *             ," << std::endl;
	outFile << "                  _/^\\_" << std::endl;
	outFile << "                 <     >" << std::endl;
	outFile << "*                 /.-.\\         *" << std::endl;
	outFile << "         *        `/&\\`                   *" << std::endl;
	outFile << "                 ,@.*;@," << std::endl;
	outFile << "                /_o.I %_\\    *" << std::endl;
	outFile << "   *           (`'--:o(_@;" << std::endl;
	outFile << "              /`;--.,__ `')  " << std::endl;
	outFile << "             ;@`o % O,*`'`&\\" << std::endl;
	outFile << "       *    (`'--)_@ ;o %'()\\      *" << std::endl;
	outFile << "            /`;--._`''--._O'@;" << std::endl;
	outFile << "           /&*,()~o`;-.,_ `""`)" << std::endl;
	outFile << "*          /`,@ ;+& () o*`;-';\\" << std::endl;
	outFile << "          (`""--.,_0 +% @' &()\\" << std::endl;
	outFile << "          /-.,_    ``''--....-'`)  *" << std::endl;
	outFile << "     *    /@%;o`:;'--,.__   __.'\\" << std::endl;
	outFile << "         ;*,&(); @ % &^;~`\"`o;@();         *" << std::endl;
	outFile << "         /(); o^~; & ().o@*&`;&%O\\" << std::endl;
	outFile << "   jgs   `\"=\"==\"\"==,,,.,=\"==\"===\"`" << std::endl;
	outFile << "      __.----.(\\-''#####---...___...-----._" << std::endl;
	outFile << "    '`         \\)_`\"\"\"\"\"`" << std::endl;
	outFile << "            .--' ')" << std::endl;
	outFile << "          o(  )_-\\" << std::endl;
	outFile << "            `\"\"\"` `" << std::endl;
	outFile.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
