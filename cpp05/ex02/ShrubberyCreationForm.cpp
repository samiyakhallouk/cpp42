#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("none")
{
    // std::cout << "\033[32mShrubbery default constructor called!\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    // std::cout << "\033[32mShrubbery constructor called!\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target)
{
    // std::cout << "\033[32mShrubbery copy constructor called!\033[0m" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    // std::cout << "\033[32mShrubbery copy assignement operator called!\033[0m" << std::endl;
    if (this != &other)
    {
        this->target = other.target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    // std::cout << "\033[32mShrubbery destructor called!\033[0m" << std::endl;
}


void  ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    this->exec_check(executor);
    std::ofstream file((target + "_shrubbery").c_str());
    if (!file)
        throw std::runtime_error("Error opening file");
    
    file << "   /\\\n";
    file << "  /**\\\n";
    file << " /****\\\n";
    file << "/******\\\n";
    file << "   ||\n";
    file << "   ||\n";

    file.close();
}
