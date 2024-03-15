#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap    CL4P_TP01("CL4P-TP01");
    ClapTrap    CL4P_TP02("CL4P-TP02");
    ClapTrap    CL4P_TP03("CL4P-TP03");
    std::cout << std::endl;

    CL4P_TP01.attack("Bandit");
    CL4P_TP02.takeDamage(7);
    std::cout << std::endl;
    
    CL4P_TP02.attack("Skag");
    CL4P_TP03.takeDamage(5);
    std::cout << std::endl;
    
    CL4P_TP03.attack("Zombie");
    CL4P_TP01.takeDamage(5);
    std::cout << std::endl;

    CL4P_TP01.beRepaired(1);
    CL4P_TP03.beRepaired(1);
    CL4P_TP03.beRepaired(1);
    std::cout << std::endl;

    CL4P_TP02.takeDamage(10);
    CL4P_TP02.attack("Spiderant");
    std::cout << std::endl;

    CL4P_TP03.takeDamage(10);
    CL4P_TP03.attack("Rakk");
    std::cout << std::endl;

    CL4P_TP01.takeDamage(10);
    CL4P_TP01.attack("Scythid");
    std::cout << std::endl;

    return 0;
}