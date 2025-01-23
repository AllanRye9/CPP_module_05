#include "../include/Intern.hpp"

Intern::Intern()
{
	makeFormFunc[0] = &Intern::makeShrubberyCreationForm;
	makeFormFunc[1] = &Intern::makeRobotomyRequestForm;
	makeFormFunc[2] = &Intern::makePresidentialPardonForm;

	formNames[0] = "shrubbery creation";
	formNames[1] = "robotomy request";
	formNames[2] = "presidential pardon";
	std::cout << "An Intern created" << std::endl;
}

Intern::Intern(const Intern &other)
{
	*this = other;
	std::cout << "An Intern created as copy from another" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	if (this != &other)
		return *this;
	return *this;
}

AForm *Intern::makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

Intern::~Intern()
{
	std::cout << "An Intern destroyed" << std::endl;
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	AForm *form = NULL;
	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			form = (this->*makeFormFunc[i])(target);
			std::cout << "Intern creates " << formName << " form" << std::endl;
			break;
		}
	}
	if (form == NULL)
		std::cout << "Intern can't create " << formName << " form" << std::endl;
	return form;
}