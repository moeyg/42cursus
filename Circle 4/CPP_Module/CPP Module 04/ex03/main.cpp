#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(void)
{
    IMateriaSource* materiaSource = new MateriaSource();
    materiaSource->learnMateria(new Ice());
    materiaSource->learnMateria(new Cure());
    
    ICharacter* ezreal = new Character("Ezreal");
    ICharacter* orianna = new Character("Orianna");
    Character*  kayn = new Character("Kayn");
    AMateria*   materia;

    materia = materiaSource->createMateria("ice");
    ezreal->equip(materia);
    materia = materiaSource->createMateria("cure");
    ezreal->equip(materia);

    materia = materiaSource->createMateria("ice");
    orianna->equip(materia);
    materia = materiaSource->createMateria("cure");
    orianna->equip(materia);

    materia = materiaSource->createMateria("ice");
    kayn->equip(materia);
    materia = materiaSource->createMateria("cure");
    kayn->equip(materia);
    materia = kayn->getInventory(0);
    kayn->unequip(0);

    ezreal->use(0, *orianna);
    ezreal->use(1, *orianna);
    orianna->use(0, *kayn);
    orianna->use(1, *kayn);
    kayn->use(0, *ezreal);  // unequip
    kayn->use(1, *ezreal);

    delete materiaSource;
    delete materia;
    delete orianna;
    delete ezreal;
    delete kayn;

    return 0;
}