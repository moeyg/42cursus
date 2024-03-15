#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap    SC4V_TP01("SC4V-TP01");
    ScavTrap    SC4V_TP02("SC4V-TP02");
    ScavTrap    SC4V_TP03("SC4V-TP03");
    std::cout << std::endl;

    SC4V_TP02.attack("Rakk");
    SC4V_TP03.takeDamage(SC4V_TP02.getAttackDamage());
    SC4V_TP01.attack("Bandit");
    SC4V_TP02.takeDamage(SC4V_TP01.getAttackDamage());
    std::cout << std::endl;

    SC4V_TP01.beRepaired(SC4V_TP01.getHitPoints());
    SC4V_TP02.beRepaired(SC4V_TP02.getHitPoints());
    SC4V_TP03.beRepaired(SC4V_TP03.getHitPoints());
    std::cout << std::endl;

    SC4V_TP01.guardGate();
    SC4V_TP02.guardGate();
    SC4V_TP03.guardGate();
    std::cout << std::endl;

    return 0;
}