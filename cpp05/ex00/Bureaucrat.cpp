#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default") , grade(150)
{
    std::cout << "DEFAULT CONSTRUCTOR IS CALLED!" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
    if (grade > 150)
    {
        throw GradeTooLowException();
    }
    else if (grade < 1)
    {
        throw GradeTooHighException();
    }
    else
        this->grade = grade;
    std::cout << "CONSTRUCTOR IS CALLED!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
    std::cout << "COPY CONSTRUCTOR IS CALLED!" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "COPY ASSI IS CALLED!" << std::endl;
    if (this != &other)
    {
        this->grade = other.grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "DESTRUCTOR IS CALLED!" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return ("\033[33mException : the Grade is too high !\033[0m");
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return ("\033[33mException : the Grade is too low !\033[0m");
}

std::string Bureaucrat::getName() const
{
    return (name);
}

int Bureaucrat::getGrade() const
{
    return (grade);
}


void Bureaucrat::increment()
{
    grade--;
    if (grade < 1)
        throw GradeTooHighException();
}

void Bureaucrat::decrement()
{
    grade++;
    if (grade > 150)
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream& out, Bureaucrat& other)
{
    out << other.getName() << ", bureaucrat grade " << other.getGrade();
    return out;
}
