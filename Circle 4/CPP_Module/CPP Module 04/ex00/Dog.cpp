#include "Dog.hpp"

Dog::Dog(void)
{
    this->type = "Dog";
    std::cout << GREEN << type << " is created." << RESET << std::endl;
}

Dog::Dog(const Dog& dog)
{
    *this = dog;
    std::cout << GREEN << type << " is created." << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& dog)
{
    if (this != &dog)
        type = dog.getType();

    std::cout << GREEN << type << " is created." << RESET << std::endl;

    return *this;
}

Dog::~Dog(void)
{
    std::cout << RED << type << " is destroyed." << RESET << std::endl;
}

void    Dog::makeSound(void) const
{
    std::cout << BLUE << "Woof woof 🐶" << RESET << std::endl;
}