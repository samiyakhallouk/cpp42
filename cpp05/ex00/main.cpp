#include "Bureaucrat.hpp"


int main()
{
    try
    {
        Bureaucrat b("anonymous", 2);
        std::cout << b << std::endl;
        b.decrement();
        std::cout << b << std::endl;
        b.increment();
        b.increment();
        std::cout << b << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}