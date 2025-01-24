#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm(){}
PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm(target, 25, 5), _target(target)
{
    std::cout << target << " PresidentialPardonForm Constructor Called " << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & copy) : AForm(copy._name, copy._gradeToSign, copy._gradeToExecute), _target(copy._target)
{
    std::cout << "PresidentialPardonForm Copy Constructor Called " << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm & copy)
{
    if (this != &copy)
    {
        const_cast<std::string &>(this->_name) = copy._name;
        const_cast<size_t &>(this->_gradeToExecute) = copy._gradeToExecute;
        const_cast<size_t &>(this->_gradeToSign) = copy._gradeToSign;
        this->_signed = copy._signed;
    }
    return *this;
}
void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    try{
        if (!this->_signed)
            throw FormNotSignedException();
        if (executor.getGrade() > _gradeToExecute)
            throw GradeTooLowException();
        std::cout << executor.getName() << "has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << "An exception ocurred due to " << std::endl;
        std::cerr << e.what() << std::endl;
    }
}
PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << _target << " PresidentialPardonForm has been Destroyed" << std::endl;
}