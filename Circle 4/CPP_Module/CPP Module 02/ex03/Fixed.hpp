#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int fixedPointNumber;
	static const int fractionalBits = 8;

public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();
	Fixed(const Fixed& fixed);

	Fixed&	operator=(const Fixed& fixed);
	bool	operator>(const Fixed& fixed) const;
	bool	operator<(const Fixed& fixed) const;
	bool	operator>=(const Fixed& fixed) const;
	bool	operator<=(const Fixed& fixed) const;
	bool	operator==(const Fixed& fixed) const;
	bool	operator!=(const Fixed& fixed) const;
	Fixed	operator+(const Fixed& fixed);
	Fixed	operator-(const Fixed& fixed);
	Fixed	operator*(const Fixed& fixed);
	Fixed	operator/(const Fixed& fixed);
	Fixed&	operator++(void);
	Fixed	operator++(int);
	Fixed&	operator--(void);
	Fixed	operator--(int);

	static Fixed&		min(Fixed& fixed1, Fixed& fixed2);
	static const Fixed&	min(const Fixed& fixed1, const Fixed& fixed2);
	static Fixed&		max(Fixed& fixed1, Fixed& fixed2);
	static const Fixed&	max(const Fixed& fixed1, const Fixed& fixed2);

	float				toFloat(void) const;
	int					toInt(void) const;

	int					getRawBits(void) const;
	void				setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& ofs, const Fixed& fixed);

#endif