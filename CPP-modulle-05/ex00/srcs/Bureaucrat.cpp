#include "../include/Bureaucrat.hpp"
    
Bureaucrat::Bureaucrat():name("default"), grade(150){};

Bureaucrat::~Bureaucrat()
{
	std::cout << std::endl << "Bureaucrat " << this->name << " destroyed" << std::endl;
}

Bureaucrat::Bureaucrat(std::string pname, size_t pgrade): name(pname)
{
	if (pgrade < 1)
		throw GradeTooHighException();
	if (pgrade > 150)
		throw GradeTooLowException();
	
	this->grade = pgrade;
	std::cout << "Bureaucrat " << this->name << " created with grade: " << this->grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat & other): name(other.name + "_Copy")
{
	this->grade = other.grade;
	std::cout << "Bureaucrat " << this->name << " with grade: " << this->grade << " Copied from " << other.name << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->grade = other.grade;
		std::cout << "Bureaucrat " << this->name << " assigned " << other.name << " grade: " << this->grade << std::endl;
	}
	return *this;
}

void Bureaucrat::gradeIncrement(void)
{
	try
	{
		if (this->grade == 1)
			throw GradeTooHighException();
		this->grade--;
		std::cout << "Bureaucrat " << this->name << " promoted" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << ' ';
		std::cerr << this->name << " Grade cannot be incremented" << std::endl;
	}
}

void Bureaucrat::gradeDecrement(void)
{
	try
	{
		if (this->grade == 150)
			throw GradeTooLowException();
		this->grade++;
		std::cout << "Bureaucrat " << this->name << " demoted" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << ' ';
		std::cerr << this->name << " Grade cannot be decremented" << std::endl;
	}
}

std::string Bureaucrat::getName(void) const
{
	return this->name;
}

size_t Bureaucrat::getGrade(void) const
{
	return this->grade;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &object)
{
    out << object.getName() << " ,bureaucrat grade " << object.getGrade() << ".";
    return out;
}