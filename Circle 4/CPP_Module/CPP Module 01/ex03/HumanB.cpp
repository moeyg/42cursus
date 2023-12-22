#include "HumanB.hpp"

HumanB::HumanB(void) { }

HumanB::~HumanB(void) { }

HumanB::HumanB(std::string name) : name(name) { }

void    HumanB::attack(void)
{
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}