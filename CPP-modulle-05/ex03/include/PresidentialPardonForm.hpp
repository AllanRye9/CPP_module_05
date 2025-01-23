#pragma once
#include "AForm.hpp"
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm{
private:
    std::string _target;
    PresidentialPardonForm();
public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm & copy);
    PresidentialPardonForm & operator = (const PresidentialPardonForm & copy);
    virtual void execute(Bureaucrat const & executor) const;
    ~PresidentialPardonForm();
};