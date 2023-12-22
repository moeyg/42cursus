#include "Zombie.hpp"

Zombie::Zombie(void) { }

Zombie::~Zombie(void)
{
    std::cout << RED << "Zombies is destroyed!" << RESET << std::endl;
}

void    Zombie::announce(void) const
{
    std::cout << YELLOW + name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}

void    Zombie::setName(std::string name)
{
    this->name = name;
}
