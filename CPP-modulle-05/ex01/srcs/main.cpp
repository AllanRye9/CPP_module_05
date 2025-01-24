#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main()
{
    Bureaucrat *officer = new Bureaucrat("Chris", 14);
    Form();
    Form person("Luda", 120, 125);
    person.beSigned(*officer);
    std::cout << person;
    delete officer;
    return 0;
}

// int main()
// {
//     Bureaucrat *officer = new Bureaucrat("Chris", 10);
//     Form person("Luda", person.getGradeToSign(), person.getGradeToExecute());
//     Form();
//     person.beSigned(*officer);
//     std::cout << person;
//     delete officer;
//     return 0;
// }