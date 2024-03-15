#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap(std::string name);
    FragTrap(const FragTrap &fragTrap);
    FragTrap&   operator=(const FragTrap& fragTrap);
    ~FragTrap(void);

    void    attack(const std::string& target);
    void    highFivesGuys(void);
};

#endif