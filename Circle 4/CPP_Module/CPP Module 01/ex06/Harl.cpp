#include "Harl.hpp"

Harl::Harl(void) { };

Harl::~Harl(void) { };

void    Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void (Harl::*func[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    int message;
    for (message = 0; message < 4; message++)
    {
        if (level == levels[message]) { break; }
    }

    switch (message)
    {
    case harlLevel::DEBUG:
        (this->*func[harlLevel::DEBUG])();
        std::cout << std::endl;
    case harlLevel::INFO:
        (this->*func[harlLevel::INFO])();
        std::cout << std::endl;
    case harlLevel::WARNING:
        (this->*func[harlLevel::WARNING])();
        std::cout << std::endl;
    case harlLevel::ERROR:
        (this->*func[harlLevel::ERROR])();
        std::cout << std::endl;
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
    }
}

void    Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
    std::cout << "I really do!" << std::endl;

}

void    Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;

}

void    Harl::warning(void)
{
    std::cout << "[ WARNING ] " << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming here for years and you just started working here last month." << std::endl;

}

void    Harl::error(void)
{
    std::cout << "[ ERROR ] " << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}