#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm;

class AForm
{
	protected:
		AForm();
		const std::string _name;
		bool _signed;
		const size_t _gradeToSign;
		const size_t _gradeToExecute;
		AForm(std::string name, size_t gradeToSign, size_t gradeToExecute);

	public:
		virtual void execute(Bureaucrat const & executor) const = 0;
		AForm(const AForm & other);
		AForm &operator=(const AForm &other);
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
		class FormNotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class FileNotOpenedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		void	        beSigned(Bureaucrat &bureaucrat);
		std::string	    getName(void) const;
		bool	        getSigned(void) const;
		size_t	        getGradeToSign(void) const;
		size_t	        getGradeToExecute(void) const;
		virtual         ~AForm();
};

std::ostream	&operator<<(std::ostream &out, const AForm &object);