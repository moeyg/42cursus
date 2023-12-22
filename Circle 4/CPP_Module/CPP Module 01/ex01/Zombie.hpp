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
    int         N;
    std::string name;

public:
    Zombie(void);
    ~Zombie(void);
    void announce(void) const;
    void setName(std::string name);
};

Zombie  *zombieHorde(int N, std::string name);

#endif