#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const size_t _gradeToSign;
		const size_t _gradeToExecute;

	public:
        Form();
		Form(std::string name, size_t gradeToSign, size_t gradeToExecute);
		Form(const Form & other);
		Form &operator=(const Form &other);
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		void		beSigned(Bureaucrat &bureaucrat);
		std::string	getName(void) const;
		bool		getSigned(void) const;
		size_t		getGradeToSign(void) const;
		size_t		getGradeToExecute(void) const;
		~Form();
};

std::ostream	&operator<<(std::ostream &out, const Form &object);