#include "../include/Bureaucrat.hpp"

int main()
{
    // Bureaucrat officer;
    Bureaucrat officer("Chris", 15);
    officer.gradeIncrement();
    // officer.gradeDecrement();
    std::cout << officer;
    return 0;
}

// int main()
// {
//     Bureaucrat officer("Chris", 3);
//     officer.gradeIncrement();
//     officer.gradeDecrement();
//     std::cout << officer;
//     return 0;
// }