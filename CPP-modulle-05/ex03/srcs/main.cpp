#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"

int	main()
{
	try
	{
		Bureaucrat  Steve("Steve", 3);
		Bureaucrat  Evans("Evans", 25);
		Bureaucrat	Rooney("Rooney", 40);
		Bureaucrat  Timothy("Timothy", 137);
		Bureaucrat	Julius("Julius", 148);

		Intern Intern;

		AForm* rrf;
		AForm* ppf;
		AForm* scf;

		rrf = Intern.makeForm("robot", "Bender");
		ppf = Intern.makeForm("presidential", "Fender");
		scf = Intern.makeForm("shrubberrequesty", "Mender");

		Rooney.signForm(*rrf);
		
	
		delete rrf;
		delete ppf;
		delete scf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}