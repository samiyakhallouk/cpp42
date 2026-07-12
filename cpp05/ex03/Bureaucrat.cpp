#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default") , grade(150)
{
    // std::cout << "\033[32mBUREAUCRAT DEFAULT CONSTRUCTOR IS CALLED!\033[0m" << std::endl;
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
    // std::cout << "\033[32mBUREAUCRAT CONSTRUCTOR IS CALLED!\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
    // std::cout << "\033[32mBUREAUCRAT COPY CONSTRUCTOR IS CALLED!\033[0m" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    // std::cout << "\033[32mBUREAUCRAT COPY ASSI IS CALLED!\033[0m" << std::endl;
    if (this != &other)
    {
        this->grade = other.grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    // std::cout << "\033[32mBUREAUCRAT DESTRUCTOR IS CALLED!\033[0m" << std::endl;
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

void Bureaucrat::signForm(AForm& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->getName() << " couldn´t sign " << form.getName() << " because : " << e.what() << std::endl;
    }
    
}

void Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->getName() << " couldn't execute " << form.getName()<< " because : " << e.what() << std::endl;
    }
}


std::ostream &operator<<(std::ostream& out, Bureaucrat& other)
{
    out << other.getName() << ", bureaucrat grade " << other.getGrade();
    return out;
}
