#include "Cat.hpp"

Cat::Cat(void)
{
    this->type = "Cat";
    std::cout << GREEN << type << " is created." << RESET << std::endl;
}

Cat::Cat(const Cat& cat)
{
    *this = cat;
    std::cout << GREEN << type << " is created." << RESET << std::endl;
}

Cat& Cat::operator=(const Cat& cat)
{
    if (this != &cat)
        type = cat.getType();

    std::cout << GREEN << type << " is created." << RESET << std::endl;

    return *this;
}

Cat::~Cat(void)
{
    std::cout << RED << type << " is destroyed." << RESET << std::endl;
}

void    Cat::makeSound(void) const
{
    std::cout << YELLOW << "Meow 🐱" << RESET << std::endl;
}