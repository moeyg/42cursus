#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << GREEN;
    std::cout << "ClapTrap [ " << name << " ] has been created.";
    std::cout << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
{
    name = clapTrap.getName();
    hitPoints = clapTrap.getHitPoints();
    energyPoints = clapTrap.getEnergyPoints();
    attackDamage = clapTrap.getAttackDamage();

    std::cout << GREEN;
    std::cout << "ClapTrap [ " << name << " ] has been created.";
    std::cout << RESET << std::endl;
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& clapTrap)
{
    if (this != &clapTrap)
    {
        name = clapTrap.getName();
        hitPoints = clapTrap.getHitPoints();
        energyPoints = clapTrap.getEnergyPoints();
        attackDamage = clapTrap.getAttackDamage();
    }

    std::cout << GREEN;
    std::cout << "ClapTrap [ " << name << " ] has been created.";
    std::cout << RESET << std::endl;

    return *this;
}

void    ClapTrap::attack(const std::string& target)
{
    if ((hitPoints <= 0) || (energyPoints <= 0))
        noPointsLeft();
    else
    {
        --energyPoints;
        std::cout << RED;
        std::cout << "ClapTrap [ " << name << " ] attacks [ " << target << " ], causing [ " << attackDamage << " ] points of damage!";
        std::cout << RESET << std::endl;
    }
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints <= amount)
        hitPoints = 0;
    else
        hitPoints -= amount;
    
    std::cout << PURPLE;
    std::cout << "[ " << name << " ] takes [ " << amount << " ] damage.";
    std::cout << RESET << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints <= 0)
    {
        std::cout << YELLOW;
        std::cout << "[ " << name << " ] has no Hit points left.";
        std::cout << RESET << std::endl;
    }
    else if (energyPoints <= 0)
    {
        std::cout << YELLOW;
        std::cout << "[ " << name << " ] has no Energy points left.";
        std::cout << RESET << std::endl;
    }
    else
    {
        --energyPoints;
        hitPoints += amount;
        if (hitPoints > 10)
            hitPoints = 10;
        
        std::cout << BLUE;
        std::cout << "[ " << name << " ]'s [ " << amount << " ] Hit points are repaired.";
        std::cout << RESET << std::endl;
    }
}

void    ClapTrap::noPointsLeft(void)
{
    std::cout << YELLOW;

    if (hitPoints <= 0)
        std::cout << "[ " << name << " ] has no Hit points left.";
    else if (energyPoints <= 0)
        std::cout << "[ " << name << " ] has no Energy points left.";

    std::cout << RESET << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << BLACK;
    std::cout << "ClapTrap [ " << name << " ] has destroyed.";
    std::cout << RESET << std::endl;
}

std::string     ClapTrap::getName(void) const
{
    return name;
}

unsigned int    ClapTrap::getHitPoints(void) const
{
    return hitPoints;
}

unsigned int    ClapTrap::getEnergyPoints(void) const
{
    return energyPoints;
}

unsigned int    ClapTrap::getAttackDamage(void) const
{
    return attackDamage;
}