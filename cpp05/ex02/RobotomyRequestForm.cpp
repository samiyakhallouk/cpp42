#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("none")
{
    // std::cout << "\033[32mRobotomy default constructor called!\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
    // std::cout << "\033[32mRobotomy constructor called!\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target)
{
    // std::cout << "\033[32mRobotomy copy constructor called!\033[0m" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    // std::cout << "\033[32mRobotomy copy assignement operator called!\033[0m" << std::endl;
    if (this != &other)
    {
        this->target = other.target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    // std::cout << "\033[32mRobotomy destructor called!\033[0m" << std::endl;
}


void  RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    this->exec_check(executor);
    std::cout << "Some drilling noises..." << std::endl;
    if (std::rand() % 2)
        std::cout << target << " has been robotomized successfully." << std::endl;
    else
        std::cout << target << " the robotomy failed." << std::endl;
}
