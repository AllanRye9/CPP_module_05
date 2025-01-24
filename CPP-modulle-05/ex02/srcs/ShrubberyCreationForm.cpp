#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :  AForm(target, 145, 137), _target(target){}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this!= &other)
    {
        const_cast<std::string &>(this->_name) = other._name;
        const_cast<size_t &>(this->_gradeToExecute) = other._gradeToExecute;
        const_cast<size_t &>(this->_gradeToSign) = other._gradeToSign;
        this->_signed = other._signed;
    }
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other._name, other._gradeToSign, other._gradeToExecute), _target(other._target){}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    try{
        if (!this->_signed)
            throw FormNotSignedException();
        if (executor.getGrade() > _gradeToExecute)
            throw GradeTooLowException();
        std::ofstream file((this->_target + "_shrubbery").c_str());
        if (!file.is_open())
            throw FileNotOpenedException();
        std::cout << "Creating a shrubbery in " << this->_target << " by " << executor.getName() << std::endl;
        file << "💣💜  𝒽𝔢𝔶 ＨẸⓇє 𝐢ⓣ ｉＳ 𝕥𝔞кє ŤＩΜｅ Ⓣ𝐎 άη𝕒ˡⓨ𝕫𝐄 𝕋ｈ𝐄 ＣㄖⓃţⓔ𝐫  ♝💚 \n"; 
        file << "𝓱𝓮𝔂 𝓱𝓮𝓻𝓮 𝓲𝓽 𝓲𝓼 𝓽𝓪𝓴𝓮 𝓽𝓲𝓶𝓮 𝓽𝓸 𝓪𝓷𝓪𝓵𝔂𝔃𝓮 𝓽𝓱𝓮 𝓬𝓸𝓷𝓽𝓮𝓻 \n"; 
        file << "ꫝꫀꪗ ꫝꫀ᥅ꫀ ꠸ꪻ ꠸ᦓ ꪻꪖᛕꫀ ꪻ꠸ꪑꫀ ꪻꪮ ꪖꪀꪖꪶꪗƺꫀ ꪻꫝꫀ ᥴꪮꪀꪻꫀ᥅ \n";
    }
    catch(const std::exception &e)
    {
        std::cerr << "ShrubberyCreationForm " << this->_target << " cannot be executed by " << executor.getName() << " because " << std::endl;
        std::cerr << e.what() << std::endl;
        return ;
    }
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm " << this->_name << " destroyed" << std::endl;
}