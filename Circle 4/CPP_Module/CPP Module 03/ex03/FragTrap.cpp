#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	name = name;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;

	std::cout << GREEN;
    std::cout << "FragTrap [ " << name << " ] has been created.";
    std::cout << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& scavTrap) : ClapTrap("FragTrap")
{
    name = scavTrap.name;
    hitPoints = scavTrap.hitPoints;
    energyPoints = scavTrap.energyPoints;
    attackDamage = scavTrap.attackDamage;

    std::cout << GREEN;
    std::cout << "FragTrap [ " << name << " ] has been created.";
    std::cout << RESET << std::endl;
}

FragTrap&   FragTrap::operator=(const FragTrap& scavTrap)
{
    if (this != &scavTrap)
    {
        name = scavTrap.getName();
        hitPoints = scavTrap.getHitPoints();
        energyPoints = scavTrap.getEnergyPoints();
        attackDamage = scavTrap.getAttackDamage();
    }

    std::cout << GREEN;
    std::cout << "FragTrap [ " << name << " ] has been created.";
    std::cout << RESET << std::endl;

    return *this;
}

void    FragTrap::attack(const std::string& target)
{
    if ((hitPoints <= 0) || (energyPoints <= 0))
        noPointsLeft();
    else
    {
        --energyPoints;
        std::cout << RED;
        std::cout << "FragTrap [ " << name << " ] attacks [ " << target << " ], causing [ " << attackDamage << " ] points of damage!";
        std::cout << RESET << std::endl;
    }
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << CYAN << "FragTrap [ " << name << " ] let's Positive High-five! 🙌" << RESET << std::endl;
}

FragTrap::~FragTrap(void)
{
    std::cout << BLACK;
    std::cout << "FragTrap [ " << name << " ] has destroyed.";
    std::cout << RESET << std::endl;
}