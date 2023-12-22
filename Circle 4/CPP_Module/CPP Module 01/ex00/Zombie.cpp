#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie(void)
{
    std::cout << RED + name << " is destroyed!" << RESET << std::endl;
}

void    Zombie::announce(void) const
{
    std::cout << YELLOW + name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}