#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int value;
        static const int fractionalbits;
    public:
        Fixed();
        Fixed(const int n);
        Fixed(const float n);
        Fixed(const Fixed &other);

        Fixed &operator=(const Fixed &other);
        
        int getRawBits( void ) const;
        void setRawBits( int const raw );

        int toInt( void ) const;
        float toFloat( void ) const;

        bool operator>(const Fixed &other) const;
        bool operator<(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;

        Fixed operator+(const Fixed &other) const;
        Fixed operator-(const Fixed &other) const;
        Fixed operator*(const Fixed &other) const;
        Fixed operator/(const Fixed &other) const;

        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);

        static Fixed& min(Fixed &x, Fixed &y);
        static const Fixed& min(const Fixed &x, const Fixed &y);
        static Fixed& max(Fixed &x, Fixed &y);
        static const Fixed& max(const Fixed &x, const Fixed &y);

        ~Fixed();
};
    
std::ostream &operator<<(std::ostream &out, const Fixed &other);

#endif