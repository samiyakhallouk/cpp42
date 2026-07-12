#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::srand(time(0));
    
    try
    {
        ShrubberyCreationForm s("s");
        RobotomyRequestForm r("r");
        PresidentialPardonForm p("p");
        Bureaucrat a("a", 5);
        std::cout << "\033[34m*********************Signing forms************************\033[0m"<< std::endl;
        a.signForm(s);
        a.signForm(r);
        a.signForm(p);
        std::cout << "\033[34m*********************executing forms**********************\033[0m"<< std::endl;
        a.executeForm(s);
        a.executeForm(r);
        a.executeForm(p);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}