#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

#include <iostream>
#include <string>

#define RED    "\033[0;31m"
#define YELLOW "\033[0;33m"
#define RESET  "\033[0m"

class Weapon
{
private:
    std::string type;

public:
    Weapon(void);
    ~Weapon(void);
    Weapon(std::string type);
    std::string getType(void) const;
    void        setType(std::string type);
};

#endif