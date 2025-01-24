#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int	main()
{
	try
	{
		Bureaucrat  Peter("Peter", 3);
		Bureaucrat  Tonny("Tonny", 25);
		Bureaucrat	James("James", 40);
		Bureaucrat  Isaac("Isaac", 137);
		Bureaucrat	Reagan("Reagan", 26);

		ShrubberyCreationForm	File1("ResearchFile");
		Reagan.signForm(File1);
		James.signForm(File1);
		File1.execute(Reagan);
		File1.execute(Isaac);

		RobotomyRequestForm	File2("SurveyFile");
		Reagan.signForm(File2);
		James.signForm(File2);
		File2.execute(Isaac);
		File2.execute(Tonny);

		PresidentialPardonForm	File3("AdmissionFile");
		James.signForm(File3);
		Tonny.signForm(File3);
		File3.execute(Tonny);
		File3.execute(Peter);
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}