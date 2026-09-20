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

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_minSign;
		const int			_minExec;
	 public:
		AForm();
		AForm(std::string name, const int minS, const int minE);
		AForm(const AForm& other);
		AForm&	operator=(const AForm& other);
		const std::string			getName() const;
		bool				 		getState() const;
		int							getMinS() const;
		int							getMinE() const;
		void						beSigned(Bureaucrat& b);
		void						execute(Bureaucrat const & executor) const;
		virtual void				executeAction() const = 0;
		virtual ~AForm();
		class	GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class	GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		class	FormNotSignedException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& other);

#endif
