#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) { }

HumanB::~HumanB(void) { }

void    HumanB::attack(void)
{
    std::cout << YELLOW + name;
    std::cout << " attacks with their " << weapon->getType() << RESET << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}