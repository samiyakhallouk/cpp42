#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal Default constructor called" << std::endl;
    this->type =  "Default";
}

Animal::Animal(const Animal &other)
{
    std::cout << "Animal Copy constructor called" << std::endl;
    *this = other;
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout << "Animal Copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

std::string Animal::getType() const
{
    return(this->type);
}

void Animal::makeSound() const
{
    std::cout << "--- animal sound ---\n";
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

