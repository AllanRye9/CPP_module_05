#include "../include/Form.hpp"
Form::Form(): _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150){};

Form::~Form()
{
    std::cout <<this->_name << " Form: Destroyed" << std::endl;
}

Form::Form(std::string name, size_t gradeToSign, size_t gradeToExecute): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form " << this->_name << " created with grade to sign " << this->_gradeToSign << " and grade to execute " << this->_gradeToExecute << std::endl;
}

Form::Form(const Form &other): _name(other._name + "_Copy"), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "Copy constructor used to make new form as copy from " << this->_name << std::endl;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		const_cast<std::string&>(this->_name) = other._name;
		const_cast<size_t&>(this->_gradeToSign) = other._gradeToSign;
		const_cast<size_t&>(this->_gradeToExecute) = other._gradeToExecute;
		this->_signed = other._signed;
		std::cout << "Copy assign operator used to create new form for " << this->_name << std::endl;
	}
	return *this;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() > this->_gradeToSign)
			throw Form::GradeTooLowException();
		this->_signed = true;
		std::cout << "Bureaucrat " << bureaucrat.getName() << " signed " <<"Form: " << this->_name << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cerr << "Bureaucrat " << bureaucrat.getName() << " cannot sign " << this->_name << std::endl;
	}
}

std::string	Form::getName(void) const
{
	return this->_name;
}

bool	Form::getSigned(void) const
{
	return this->_signed;
}

size_t	Form::getGradeToSign(void) const
{
	return this->_gradeToSign;
}

size_t	Form::getGradeToExecute(void) const
{
	return this->_gradeToExecute;
}

std::ostream &operator<<(std::ostream &out, const Form &object)
{
	out << "Form " << object.getName() << " is " << (object.getSigned() ? "signed" : "not signed") << " and requires grade " << object.getGradeToSign() << " to sign and grade " << object.getGradeToExecute() << " to execute.";
	return out;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form exception, Grade is too low";
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Form exception, Grade is too high";
}