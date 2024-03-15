#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
    ScavTrap    SC4V_TP("SC4V-TP");
    FragTrap    FR4G_TP("FR4G-TP");
    DiamondTrap DIAMOND_TP("DIAMOND-TP");
    std::cout << std::endl;

    FR4G_TP.attack("Bandit");
    FR4G_TP.takeDamage(FR4G_TP.getAttackDamage());
    SC4V_TP.attack("Zombie");
    SC4V_TP.takeDamage(SC4V_TP.getAttackDamage());
    DIAMOND_TP.attack("Skag");
    DIAMOND_TP.takeDamage(DIAMOND_TP.getAttackDamage());
    std::cout << std::endl;

    SC4V_TP.beRepaired(SC4V_TP.getHitPoints());
    FR4G_TP.beRepaired(FR4G_TP.getHitPoints());
    DIAMOND_TP.beRepaired(DIAMOND_TP.getHitPoints());
    std::cout << std::endl;

    SC4V_TP.guardGate();
    FR4G_TP.highFivesGuys();
    DIAMOND_TP.whoAmI();
    std::cout << std::endl;

    return 0;
}