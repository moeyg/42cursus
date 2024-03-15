#include "Brain.hpp"

Brain::Brain(void)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "NULL";
    std::cout << GREEN << "Brain is created." << RESET << std::endl;
}

Brain::Brain(const Brain& brain)
{
    *this = brain;
    std::cout << GREEN << "Brain is created." << RESET << std::endl;
}

Brain&  Brain::operator=(const Brain& brain)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = brain.ideas[i];

    std::cout << GREEN << "Brain is created." << RESET << std::endl;

    return *this;
}

Brain::~Brain(void)
{
    std::cout << RED << "Brain is destroyed." << RESET << std::endl;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 100 || index < 0)
        return ("I don't remember...");
    return this->ideas[index];
}

void    Brain::setIdea(int index, std::string idea)
{
    if (index >= 100 || index < 0)
    {
        std::cout << "I can't think anymore..." << std::endl;
        return;
    }
    this->ideas[index] = idea;
}