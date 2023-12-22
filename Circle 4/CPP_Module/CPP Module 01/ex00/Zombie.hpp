#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#define RED    "\033[0;31m"
#define YELLOW "\033[0;33m"
#define RESET  "\033[0m"

#include <iostream>
#include <string>

class Zombie
{
private:
    std::string name;

public:
    Zombie(std::string name);
    ~Zombie(void);
    void    announce(void) const;
};

void    randomChump(std::string name);
Zombie  *newZombie(std::string name);

#endif