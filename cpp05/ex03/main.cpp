#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern intern;
    try
    {
        
        AForm* f = intern.makeForm("shrubbery creation", "Bender");
        try
        {
            Bureaucrat b("b", 78);
            // b.increment();
            b.signForm(*f);
            b.executeForm(*f);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        
        delete f;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}