#include "Intern.hpp"

Intern::Intern()
{
    // std::cout << "\033[32mIntern default constructor called!\033[0m" << std::endl;
}

Intern::Intern(const Intern& other)
{
    (void)other;
    // std::cout << "\033[32mIntern copy constructor called!\033[0m" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
    // std::cout << "\033[32mIntern copy assignement operator called!\033[0m" << std::endl;
    (void)other;
    return (*this);
}

Intern::~Intern()
{
    // std::cout << "\033[32mPresidentia destructor called!\033[0m" << std::endl;
}

AForm* makeShrubbery(std::string t)
{
    return (new ShrubberyCreationForm(t));
}

AForm* makeRobotomy(std::string t)
{
    return (new RobotomyRequestForm(t));
}

AForm* makePresidential(std::string t)
{
    return (new PresidentialPardonForm(t));
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (*ptr[3])(std::string) = {makeShrubbery, makeRobotomy, makePresidential};
    for (int i = 0; i < 3; i++)
    {
        if (name == names[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return (ptr[i](target));
        }
    }
    std::cout << "Intern connot create form " << name << std::endl;
    return (NULL);
}