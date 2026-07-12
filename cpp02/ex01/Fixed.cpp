#include "Fixed.hpp"

const int Fixed::fractionalbits = 8;

Fixed::Fixed() : value(0)
{
    std::cout << "->Default constructor called<-" << std::endl;
}

Fixed::Fixed(const int n)
{
    std::cout << "->Int constructor called<-" << std::endl;
    value = n << fractionalbits;
}

Fixed::Fixed(const float n)
{
    std::cout << "->Float constructor called<-" << std::endl;
    value = roundf(n * (1 << fractionalbits));
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "->Copy constructor called<-" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "->Copy assignment operator called<-" << std::endl;
    if (this != &other)
        this->value = other.getRawBits();
    return (*this);
}

int Fixed::getRawBits( void ) const
{
    std::cout << "->getRawBits member function called<-" << std::endl;
    return (value);
}

void Fixed::setRawBits( int const raw )
{
    this->value = raw;
}

int Fixed::toInt( void ) const
{
    return (value >> fractionalbits);
}
float Fixed::toFloat( void ) const
{
    return ((float)value / (1 << fractionalbits));
}

std::ostream &operator<<(std::ostream &out, const Fixed &other)
{
    out << other.toFloat();
    return (out);
}

Fixed::~Fixed()
{
    std::cout << "->Destructor called<-" << std::endl;
}
