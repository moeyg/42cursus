#include "Fixed.hpp"

Fixed::Fixed() : fixedPointNumber(0) { }

Fixed::Fixed(const int value) : fixedPointNumber(value << Fixed::fractionalBits) { }

Fixed::Fixed(const float value) : fixedPointNumber(roundf(value * (1 << Fixed::fractionalBits))) { }

Fixed::~Fixed() { }

Fixed::Fixed(const Fixed& fixed)
{
	fixedPointNumber = fixed.fixedPointNumber;
}

int		Fixed::getRawBits(void) const
{
	return fixedPointNumber;
}

void	Fixed::setRawBits(int const raw)
{
	fixedPointNumber = raw;
}

float	Fixed::toFloat(void) const
{
	return fixedPointNumber / (1 << Fixed::fractionalBits);
}

int		Fixed::toInt(void) const
{
	return fixedPointNumber >> Fixed::fractionalBits;
}

std::ostream& operator<<(std::ostream& ofs, const Fixed& fixed)
{
	return (ofs << fixed.toFloat());
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	fixedPointNumber = fixed.getRawBits();
	return *this;
}

bool	Fixed::operator>(const Fixed& fixed) const
{
	return fixedPointNumber > fixed.getRawBits();
}

bool	Fixed::operator<(const Fixed& fixed) const
{
	return fixedPointNumber < fixed.getRawBits();
}

bool	Fixed::operator>=(const Fixed& fixed) const
{
	return fixedPointNumber >= fixed.getRawBits();
}

bool	Fixed::operator<=(const Fixed& fixed) const
{
	return fixedPointNumber <= fixed.getRawBits();
}

bool	Fixed::operator==(const Fixed& fixed) const
{
	return fixedPointNumber == fixed.getRawBits();
}

bool	Fixed::operator!=(const Fixed& fixed) const
{
	return fixedPointNumber != fixed.getRawBits();
}

Fixed	Fixed::operator+(const Fixed& fixed)
{
	Fixed temp(this->toFloat() + fixed.toFloat());
	return temp;
}

Fixed	Fixed::operator-(const Fixed& fixed)
{
	Fixed temp(this->toFloat() - fixed.toFloat());
	return temp;
}

Fixed	Fixed::operator*(const Fixed& fixed)
{
	Fixed temp(this->toFloat() * fixed.toFloat());
	return temp;
}

Fixed	Fixed::operator/(const Fixed& fixed)
{
	Fixed temp(this->toFloat() / fixed.toFloat());
	return temp;
}

Fixed&	Fixed::operator++(void)
{
	++fixedPointNumber;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	++fixedPointNumber;
	return temp;
}

Fixed&	Fixed::operator--(void)
{
	--fixedPointNumber;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	--fixedPointNumber;
	return temp;
}

Fixed&	Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1 < fixed2)
		return (fixed1);
	return (fixed2);
}

const Fixed&	Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1 < fixed2)
		return (fixed1);
	return (fixed2);
}

Fixed&	Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1 > fixed2)
		return (fixed1);
	return (fixed2);
}

const Fixed&	Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1 > fixed2)
		return (fixed1);
	return (fixed2);
}