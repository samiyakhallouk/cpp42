#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        const int grade_sign;
        const int grade_exec;
        bool is_signed;
    public:
        AForm();
        AForm(const std::string, const int, const int);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

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
        class NotSignedException : public std::exception
        {
            public:
                const char *what() const throw();
        };

        std::string getName() const;
        int getGrade_sign() const;
        int getGrade_exec() const;
        bool getS() const;

        void beSigned(const Bureaucrat& b);

        virtual void execute(Bureaucrat const & executor) const = 0;
        void exec_check(const Bureaucrat& executor) const;
};

std::ostream &operator<<(std::ostream& out, AForm& other);


#endif