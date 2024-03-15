#include "Dog.hpp"

Dog::Dog(void)
{
    this->type = "Dog";
    this->brain = new Brain();

    std::cout << GREEN << type << " is created." << RESET << std::endl;
}

Dog::Dog(const Dog& dog)
{
    *this = dog;
    this->brain = new Brain();

    std::cout << GREEN << type << " is created." << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& dog)
{
    this->type = dog.type;
    for (int i = 0; i < 100; i++)
        this->brain->setIdea(i, dog.brain->getIdea(i));

    std::cout << GREEN << type << " is created." << RESET << std::endl;    

    return *this;
}

Dog::~Dog(void)
{
    delete this->brain;
    std::cout << RED << type << " is destroyed." << RESET << std::endl;
}

void    Dog::makeSound(void) const
{
    std::cout << BLUE << "Woof woof 🐶" << RESET << std::endl;
}

Brain&  Dog::getBrain(void)
{
    return *this->brain;
}