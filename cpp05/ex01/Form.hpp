#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        const int grade_sign;
        const int grade_exec;
        bool is_signed;
    public:
        Form();
        Form(const std::string, const int, const int);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };

        std::string getName() const;
        int getGrade_sign() const;
        int getGrade_exec() const;
        bool getS() const;

        void beSigned(const Bureaucrat& b);
};

std::ostream &operator<<(std::ostream& out, Form& other);


#endif