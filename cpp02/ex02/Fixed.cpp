#include "Fixed.hpp"

const int Fixed::fractionalbits = 8;

Fixed::Fixed() : value(0)
{
    // std::cout << "->Default constructor called<-" << std::endl;
}

Fixed::Fixed(const int n)
{
    // std::cout << "->Int constructor called<-" << std::endl;
    value = n << fractionalbits;
}

Fixed::Fixed(const float n)
{
    // std::cout << "->Float constructor called<-" << std::endl;
    value = roundf(n * (1 << fractionalbits));
}

Fixed::Fixed(const Fixed& other)
{
    // std::cout << "->Copy constructor called<-" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    // std::cout << "->Copy assignment operator called<-" << std::endl;
    if (this != &other)
        this->value = other.getRawBits();
    return (*this);
}

int Fixed::getRawBits( void ) const
{
    // std::cout << "->getRawBits member function called<-" << std::endl;
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

bool Fixed::operator>(const Fixed &other) const
{
    return (value > other.value);
}

bool Fixed::operator<(const Fixed &other) const
{
    return (value < other.value);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (value >= other.value);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (value <= other.value);
}

bool Fixed::operator==(const Fixed &other) const
{
    return (value == other.value);
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (value != other.value);
}

Fixed Fixed::operator+(const Fixed &other) const
{  
    Fixed res;
    res.value = value + other.value;
    return (res);    
}
Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed res;
    res.value = value - other.value;
    return (res);
}
Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed res;
    res.value = (value * other.value) >> fractionalbits;
    return (res);
}
Fixed Fixed::operator/(const Fixed &other) const
{
    if (other.value == 0)
    {
        std::cerr << "Division impossible!!" << std::endl;
        exit(1);
    }
    Fixed res;
    res.value = (value << fractionalbits) / other.value;
    return (res);
}

Fixed& Fixed::operator++()
{
    ++value;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    value++;
    return (tmp);
}

Fixed& Fixed::operator--()
{
    --value;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    value--;
    return (tmp);
}

Fixed& Fixed::min(Fixed &x, Fixed &y)
{
    if (x < y)
        return (x);
    return (y);
}

const Fixed& Fixed::min(const Fixed &x, const Fixed &y)
{
    if (x < y)
        return (x);
    return (y);
}

Fixed& Fixed::max(Fixed &x, Fixed &y)
{
    if (x > y)
        return (x);
    return (y);
}

const Fixed& Fixed::max(const Fixed &x, const Fixed &y)
{
    if (x > y)
        return (x);
    return (y);
}


Fixed::~Fixed()
{
    // std::cout << "->Destructor called<-" << std::endl;
}
