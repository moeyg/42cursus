#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
    this->type = "WrongCat";
    std::cout << GREEN << type << " is created." << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongCat)
{
    *this = wrongCat;
    std::cout << GREEN << type << " is created." << RESET << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& wrongCat)
{
    if (this != &wrongCat)
        type = wrongCat.getType();

    std::cout << GREEN << type << " is created." << RESET << std::endl;

    return *this;
}

WrongCat::~WrongCat(void)
{
    std::cout << RED << type << " is destroyed." << RESET << std::endl;
}

void    WrongCat::makeSound(void) const
{
    std::cout << YELLOW << "Meow 🐱" << RESET << std::endl;
}