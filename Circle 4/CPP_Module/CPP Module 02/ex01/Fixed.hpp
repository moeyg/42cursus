#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>
#include <cmath>

#define BLACK   "\033[0;30m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define PURPLE  "\033[0;35m"
#define CYAN    "\033[0;36m"
#define RESET   "\033[0m"

class Fixed
{
private:
    int                 fixedPointNumber;
    static const int    fractionalBits = 8;

public:
    Fixed();
    ~Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed& fixed);
    Fixed&  operator=(const Fixed& fixed);

    float   toFloat(void) const;
    int     toInt(void) const;
    
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& ofs, const Fixed& fixed);

#endif