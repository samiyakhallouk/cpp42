#include "AForm.hpp"

AForm::AForm() : name("Default"), grade_sign(150), grade_exec(150), is_signed(false)
{
    // std::cout << "\033[32mFORM FORM DEFAULT CONSTRUCTOR IS CALLED!\033[0m" << std::endl;
}

AForm::AForm(const std::string name, const int g_s, const int g_e) : name(name), grade_sign(g_s), grade_exec(g_e), is_signed(false)
{
    if (g_s > 150 || g_e > 150)
    {
        throw GradeTooLowException();
    }
    else if (g_s < 1 || g_e < 1)
    {
        throw GradeTooHighException();
    }
    // std::cout << "\033[32mFORM CONSTRUCTOR IS CALLED!\033[0m" << std::endl;
}

AForm::AForm(const AForm& other) : name(other.name), grade_sign(other.grade_sign), grade_exec(other.grade_exec), is_signed(false)
{
    // std::cout << "\033[32mFORM COPY CONSTRUCTOR IS CALLED!\033[0m" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
    // std::cout << "\033[32mFORM COPY ASSI IS CALLED!\033[0m" << std::endl;
    if (this != &other)
    {
        this->is_signed = other.is_signed;
    }
    return (*this);
}

AForm::~AForm()
{
    // std::cout << "\033[32mFORM DESTRUCTOR IS CALLED!\033[0m" << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw(){
    return ("\033[33mException : the Grade is too high !\033[0m");
}

const char* AForm::GradeTooLowException::what() const throw(){
    return ("\033[33mException : the Grade is too low !\033[0m");
}

const char* AForm::NotSignedException::what() const throw(){
    return ("\033[33mException : Form isn´t signed !\033[0m");
}

std::string AForm::getName() const
{
    return (name);
}

int AForm::getGrade_sign() const
{
    return (grade_sign);
}

int AForm::getGrade_exec() const
{
    return (grade_exec);
}

bool AForm::getS() const
{
    return (is_signed);
}

void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > grade_sign)
        throw GradeTooLowException();
    this->is_signed = true;
}

void AForm::exec_check(const Bureaucrat& executor) const
{
    if (!is_signed)
        throw NotSignedException();
    else if (executor.getGrade() > grade_exec)
        throw GradeTooLowException();
}


std::ostream &operator<<(std::ostream& out, AForm& other)
{
    out << other.getName() << ", grade required to sign it : "<< other.getGrade_sign() << ", grade required to execute it : " << other.getGrade_exec() << ", is signed : " << other.getS();
    return out;
}