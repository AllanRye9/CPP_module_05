#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int	main()
{
	try
	{
		Bureaucrat  samia("Samia", 3);
		Bureaucrat  mohra("Mohra", 25);
		Bureaucrat	bob("Bob", 40);
		Bureaucrat  tukka("Tukka", 137);
		Bureaucrat	jim("Jim", 148);

		ShrubberyCreationForm	tree("palmtree");
		jim.signForm(tree);
		bob.signForm(tree);
		tree.execute(jim);
		tree.execute(tukka);

		RobotomyRequestForm	robot("robot");
		jim.signForm(robot);
		bob.signForm(robot);
		robot.execute(tukka);
		robot.execute(mohra);

		PresidentialPardonForm	pardon("pardon");
		bob.signForm(pardon);
		mohra.signForm(pardon);
		pardon.execute(mohra);
		pardon.execute(samia);
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}