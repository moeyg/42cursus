#ifndef __HUMANA_HPP__
#define __HUMANA_HPP__

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
private:
    std::string name;
    Weapon      &weapon;

public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA(void);
    void    attack(void) const;
};

#endif