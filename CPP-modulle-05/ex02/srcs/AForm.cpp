#include "../include/AForm.hpp"
AForm::AForm(): _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150){};

AForm::AForm(std::string name, size_t gradeToSign, size_t gradeToExecute): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	std::cout << this->_name << " created at AForm abstract class" << std::endl;
}

AForm::AForm(const AForm &other): _name(other._name + "_Copy"), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "Copy constructor used to make new form as copy from " << this->_name << std::endl;
}

AForm &AForm::operator=(const AForm &other)
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

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() > this->_gradeToSign)
			throw AForm::GradeTooLowException();
		this->_signed = true;
		std::cout << "Bureaucrat " << bureaucrat.getName() << " signed " << this->_name << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cerr << "Bureaucrat " << bureaucrat.getName() << " cannot sign " << this->_name << std::endl;
	}
}

std::string	AForm::getName(void) const
{
	return this->_name;
}

bool	AForm::getSigned(void) const
{
	return this->_signed;
}

size_t	AForm::getGradeToSign(void) const
{
	return this->_gradeToSign;
}

size_t	AForm::getGradeToExecute(void) const
{
	return this->_gradeToExecute;
}


const char *AForm::GradeTooLowException::what() const throw()
{
	return "AForm exception, Grade is too low";
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "AForm exception, Grade is too high";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "AForm exception, Form is not signed";
}

const char *AForm::FileNotOpenedException::what() const throw()
{
	return "AForm exception, File is not open";
}

std::ostream &operator<<(std::ostream &out, const AForm &object)
{
	out << "AForm " << object.getName() << " is " << (object.getSigned() ? "signed" : "not signed") << " and requires grade " << object.getGradeToSign() << " to sign and grade " << object.getGradeToExecute() << " to execute.";
	return out;
}

AForm::~AForm()
{
	std::cout << this->_name << " has been destroyed " << std::endl;
}