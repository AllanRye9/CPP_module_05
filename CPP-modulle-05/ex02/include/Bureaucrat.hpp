#pragma once

#include <iostream>
#include <exception>
#include "AForm.hpp"
class AForm;

class Bureaucrat
{
private:
	const std::string	name;
	size_t				grade;
public:
    Bureaucrat();
	Bureaucrat(std::string pname, size_t pgrade);
	Bureaucrat(const Bureaucrat & other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

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

	void			gradeIncrement();
	void			gradeDecrement();
	std::string		getName(void) const;
	size_t			getGrade(void) const;
	void			signForm(AForm &form);
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &object);