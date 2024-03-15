#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
    std::cout << GREEN << type << " is created." << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wrongAnimal) : type(wrongAnimal.getType())
{
    std::cout << GREEN << type << " is created." << RESET << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wrongAnimal)
{
    if (this != &wrongAnimal)
        type = wrongAnimal.getType();

    std::cout << GREEN << type << " is created." << RESET << std::endl;

    return *this;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << RED << type << " is destroyed." << RESET << std::endl;
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << PURPLE << "I'm wrrrrrrrong!" << RESET << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return this->type;
}