#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	name = name;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;

	std::cout << GREEN;
    std::cout << "ScavTrap [ " << name << " ] has been created.";
    std::cout << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap) : ClapTrap("ScavTrap")
{
    name = scavTrap.name;
    hitPoints = scavTrap.hitPoints;
    energyPoints = scavTrap.energyPoints;
    attackDamage = scavTrap.attackDamage;

    std::cout << GREEN;
    std::cout << "ScavTrap [ " << name << " ] has been created.";
    std::cout << RESET << std::endl;
}

ScavTrap&   ScavTrap::operator=(const ScavTrap& scavTrap)
{
    if (this != &scavTrap)
    {
        name = scavTrap.getName();
        hitPoints = scavTrap.getHitPoints();
        energyPoints = scavTrap.getEnergyPoints();
        attackDamage = scavTrap.getAttackDamage();
    }

    std::cout << GREEN;
    std::cout << "ScavTrap [ " << name << " ] has been created.";
    std::cout << RESET << std::endl;

    return *this;
}

void    ScavTrap::attack(const std::string& target)
{
    if ((hitPoints <= 0) || (energyPoints <= 0))
        noPointsLeft();
    else
    {
        --energyPoints;
        std::cout << RED;
        std::cout << "ScavTrap [ " << name << " ] attacks [ " << target << " ], causing [ " << attackDamage << " ] points of damage!";
        std::cout << RESET << std::endl;
    }
}

void    ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap [ " << name << " ] switches to gate keeper mode." << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << BLACK;
    std::cout << "ScavTrap [ " << name << " ] has destroyed.";
    std::cout << RESET << std::endl;
}