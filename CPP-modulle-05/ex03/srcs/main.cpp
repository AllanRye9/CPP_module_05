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
		Bureaucrat  samia("Samia", 3);
		Bureaucrat  mohra("Mohra", 25);
		Bureaucrat	bob("Bob", 40);
		Bureaucrat  tukka("Tukka", 137);
		Bureaucrat	jim("Jim", 148);

		Intern someRandomIntern;

		AForm* rrf;
		AForm* ppf;
		AForm* scf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		ppf = someRandomIntern.makeForm("presidential pardon", "Fender");
		scf = someRandomIntern.makeForm("shrubbery creation", "Mender");

		bob.signForm(*rrf);
		
	
		delete rrf;
		delete ppf;
		delete scf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}