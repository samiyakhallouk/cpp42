#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("none")
{
    // std::cout << "\033[32mPresidentia default constructor called!\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
    // std::cout << "\033[32mPresidentia constructor called!\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.target)
{
    // std::cout << "\033[32mPresidentia copy constructor called!\033[0m" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    // std::cout << "\033[32mPresidentia copy assignement operator called!\033[0m" << std::endl;
    if (this != &other)
    {
        this->target = other.target;
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    // std::cout << "\033[32mPresidentia destructor called!\033[0m" << std::endl;
}


void  PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    this->exec_check(executor);
    std::cout << target <<" has been pardoned by Zaphod Beeblebrox." << std::endl;   
}
