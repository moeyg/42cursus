#include "Animal.hpp"

Animal::Animal(void) : type("Animal")
{
    std::cout << GREEN << type << " is created." << RESET << std::endl;
}

Animal::Animal(const Animal& animal) : type(animal.getType())
{
    std::cout << GREEN << type << " is created." << RESET << std::endl;
}

Animal& Animal::operator=(const Animal& animal)
{
    if (this != &animal)
        type = animal.getType();

    std::cout << GREEN << type << " is created." << RESET << std::endl;

    return *this;
}

Animal::~Animal(void)
{
    std::cout << RED << type << " is destroyed." << RESET << std::endl;
}

void    Animal::makeSound(void) const
{
    std::cout << PURPLE << "I'm rrrrrrrright!" << RESET << std::endl;
}

std::string Animal::getType(void) const
{
    return this->type;
}