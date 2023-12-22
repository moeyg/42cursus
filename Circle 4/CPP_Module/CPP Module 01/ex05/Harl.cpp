#include "Harl.hpp"

Harl::Harl(void) { };

Harl::~Harl(void) { };

void    Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void (Harl::*func[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int message = 0; message < 4; message++)
    {
        if (levels[message] == level)
            (this->*func[message])();
    }
}

void    Harl::debug(void)
{
    std::cout << GREEN;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!";
    std::cout << RESET << std::endl;
}

void    Harl::info(void)
{
    std::cout << BLACK;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
    std::cout << RESET << std::endl;
}

void    Harl::warning(void)
{
    std::cout << YELLOW;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.";
    std::cout << RESET << std::endl;

}

void    Harl::error(void)
{
    std::cout << RED;
	std::cout << "This is unacceptable! I want to speak to the manager now.";
    std::cout << RESET << std::endl;
}