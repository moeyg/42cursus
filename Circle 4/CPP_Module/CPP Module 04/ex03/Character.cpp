#include "Character.hpp"

Character::Character(void)
{
    this->name = "unknown";
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::Character(std::string name)
{
    this->name = name;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::Character(const Character& character)
{
    *this = character;
}

Character& Character::operator=(const Character& character)
{
    this->name = character.name;
    for (int i = 0; i < 4; i++)
    {
        delete this->inventory[i];
        if (character.inventory[i])
            this->inventory[i] = character.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
    return *this;
}

Character::~Character(void)
{
    for (int i = 0; i < 4; i++)
        delete this->inventory[i];
}

const std::string&   Character::getName(void) const
{
    return this->name;
}

AMateria*    Character::getInventory(int index) const
{
    if (index < 0 || index > 3)
        return NULL;
    return this->inventory[index];
}

void    Character::equip(AMateria* aMateria)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] == NULL)
        {
            this->inventory[i] = aMateria;
            break;
        }
    }
}

void    Character::unequip(int index)
{
    if (index >= 0 && index <= 3)
        this->inventory[index] = NULL;
}

void    Character::use(int index, ICharacter& target)
{
    if (0 <= index && index <= 3 && this->inventory[index])
		this->inventory[index]->use(target);
}