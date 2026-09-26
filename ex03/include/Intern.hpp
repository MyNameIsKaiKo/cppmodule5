/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 14:21:36 by jleray            #+#    #+#             */
/*   Updated: 2026/09/26 14:21:36 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include <exception>

class AForm;

class Intern
{
	private:

	 public:
		Intern();
		Intern(const Intern& other);
		Intern&				operator=(const Intern& other);
		AForm*				makeForm(std::string name, std::string target);
		~Intern();
		
};

#endif
