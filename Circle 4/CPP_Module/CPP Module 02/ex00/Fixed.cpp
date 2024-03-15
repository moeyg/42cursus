#include "Fixed.hpp"

Fixed::Fixed() : fixedPointNumber(0)
{
    std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
    std::cout << BLACK << "Copy constructor called" << RESET << std::endl;
    *this = fixed;
}

Fixed&  Fixed::operator=(const Fixed& fixed)
{
    std::cout << BLUE << "Copy assignment operator called" << RESET << std::endl;
    if (this != &fixed)
        fixedPointNumber = fixed.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << YELLOW << "getRawBits member function called" << RESET << std::endl;
    return fixedPointNumber;
}

void    Fixed::setRawBits(int const raw)
{
    fixedPointNumber = raw;
}

Fixed::~Fixed()
{
    std::cout << RED << "Destructor called" << RESET << std::endl;
}