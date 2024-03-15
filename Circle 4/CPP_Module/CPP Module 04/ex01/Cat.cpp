#include "Cat.hpp"

Cat::Cat(void)
{
    this->type = "Cat";
    this->brain = new Brain();

    std::cout << GREEN << type << " is created." << RESET << std::endl;
}

Cat::Cat(const Cat& cat)
{
    *this = cat;
    this->brain = new Brain();

    std::cout << GREEN << type << " is created." << RESET << std::endl;
}

Cat& Cat::operator=(const Cat& cat)
{
    this->type = cat.type;
    for (int i = 0; i < 100; i++)
        this->brain->setIdea(i, cat.brain->getIdea(i));

    std::cout << GREEN << type << " is created." << RESET << std::endl;

    return *this;
}

Cat::~Cat(void)
{
    delete this->brain;
    std::cout << RED << type << " is destroyed." << RESET << std::endl;
}

void    Cat::makeSound(void) const
{
    std::cout << YELLOW << "Meow 🐱" << RESET << std::endl;
}

Brain&  Cat::getBrain(void)
{
    return *this->brain;
}