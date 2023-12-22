#ifndef __HUMANB_HPP__
#define __HUMANB_HPP__

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB
{
private:
    std::string name;
    Weapon      *weapon;

public:
    HumanB(void);
    ~HumanB(void);
    HumanB(std::string name);
    void    attack(void);
    void    setWeapon(Weapon &weapon);
};

#endif