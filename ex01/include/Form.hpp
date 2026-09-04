/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 16:54:21 by jleray            #+#    #+#             */
/*   Updated: 2026/09/04 16:54:21 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_minSign;
		const int			_minExec;
	 public:
		Form();
		Form(std::string name, const int minS, const int minE);
		Form(const Form& other);
		Form&	operator=(const Form& other);
		const std::string	getName() const;
		bool		 		getState() const;
		int					getMinS() const;
		int					getMinE() const;
		void				beSigned(Bureaucrat& b);
		~Form();
		class	GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class	GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& other);

#endif
