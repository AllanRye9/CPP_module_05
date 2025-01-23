#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm(){}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45), _target(target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
    if (this != &other)
    {
        const_cast<std::string &>(this->_name) = other._name;
        const_cast<size_t &>(this->_gradeToExecute) = other._gradeToExecute;
        const_cast<size_t &>(this->_gradeToSign) = other._gradeToSign;
        this->_signed = other._signed;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    std::srand(std::time(0));
    int halfsucess = std::rand() % (100 - 1 + 1) + 1;
    try{
        if (executor.getGrade() > _gradeToExecute)
            throw GradeTooLowException();
        if (!this->_signed)
            throw FormNotSignedException();
        std::cout << "RobotomyRequestForm" << this->_name << " to be exectued by " << executor.getName() << std::endl;
        halfsucess = halfsucess % 2;
        if (halfsucess)
            std::cout << "* drilling noises * " << this->_target << " has been robotomized successfully" << std::endl;
        else
            std::cout << this->_target << " failed to robotomize" << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << '\n';
		std::cerr << "RobotomyRequestForm " << this->_name << " cannot be executed by " << executor.getName() << std::endl;
		return ;
    }
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target){}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm " << this->_target << " has been destroyed" << std::endl;
}