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
    HumanB(std::string name);
    ~HumanB(void);
    void    attack(void);
    void    setWeapon(Weapon &weapon);
};

#endif