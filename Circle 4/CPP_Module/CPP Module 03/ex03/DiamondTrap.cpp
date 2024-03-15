#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
    this->name = name;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 30;

    std::cout << GREEN;
    std::cout << "DiamondTrap [ " << name << " ] has been created.";
    std::cout << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap) : ClapTrap("ClapTrap"), ScavTrap("ScavTrap"), FragTrap("FragTrap")
{
    name = diamondTrap.name;
    hitPoints = diamondTrap.hitPoints;
    energyPoints = diamondTrap.energyPoints;
    attackDamage = diamondTrap.attackDamage;

    std::cout << GREEN;
    std::cout << "DiamondTrap [ " << name << " ] has been created.";
    std::cout << RESET << std::endl;
}

DiamondTrap&   DiamondTrap::operator=(const DiamondTrap& diamondTrap)
{
    if (this != &diamondTrap)
    {
        name = diamondTrap.getName();
        hitPoints = diamondTrap.getHitPoints();
        energyPoints = diamondTrap.getEnergyPoints();
        attackDamage = diamondTrap.getAttackDamage();
    }

    std::cout << GREEN;
    std::cout << "FragTrap [ " << name << " ] has been created.";
    std::cout << RESET << std::endl;

    return *this;
}

void    DiamondTrap::attack(const std::string& target)
{
    if ((hitPoints <= 0) || (energyPoints <= 0))
        noPointsLeft();
    else
    {
        --energyPoints;
        std::cout << RED;
        std::cout << "DiamondTrap [ " << name << " ] attacks [ " << target << " ], causing [ " << attackDamage << " ] points of damage!";
        std::cout << RESET << std::endl;
    }
}

void    DiamondTrap::whoAmI(void)
{
    std::cout << YELLOW;
    std::cout << "DiamondTrap name is [ " << name << " ]." << std::endl;
    std::cout << "ClapTrap name is [ " << ClapTrap::getName() << " ].";
    std::cout << RESET << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << BLACK;
    std::cout << "DiamondTrap [ " << name << " ] has destroyed.";
    std::cout << RESET << std::endl;
}