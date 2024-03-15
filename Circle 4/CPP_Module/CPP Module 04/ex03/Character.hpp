#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class Character : public ICharacter
{
private:
    AMateria*   inventory[4];
    std::string name;

public:
    Character(void);
    Character(std::string name);
    Character(const Character& character);
    Character&  operator=(const Character &character);
    ~Character(void);

    const std::string&  getName(void) const;
    AMateria*           getInventory(int index) const;
    void                equip(AMateria* aMateria);
    void                unequip(int index);
    void                use(int index, ICharacter& target);
};

#endif