#include "Zombie.hpp"

int main(void)
{
    Zombie stackZombie("stackZombie");
    stackZombie.announce();

    Zombie *heapZombie = newZombie("heapZombie");
    heapZombie->announce();
    delete heapZombie;

    randomChump("randomChumpZombie");

    return 0;
}