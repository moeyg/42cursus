#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) { }

HumanA::~HumanA(void) { }

void    HumanA::attack(void) const
{
    std::cout << RED + name;
    std::cout << " attacks with their " << weapon.getType() << RESET << std::endl;
}