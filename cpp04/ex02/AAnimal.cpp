#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    std::cout << "AAnimal Default constructor called" << std::endl;
    this->type =  "Default";
}

AAnimal::AAnimal(const AAnimal &other)
{
    std::cout << "AAnimal Copy constructor called" << std::endl;
    *this = other;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
    std::cout << "AAnimal Copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

std::string AAnimal::getType() const
{
    return(this->type);
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal Destructor called" << std::endl;
}
