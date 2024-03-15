#ifndef __MATERIASOURCE_HPP__
#define __MATERIASOURCE_HPP__

#include "IMateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria    *source[4];

public:
    MateriaSource(void);
    MateriaSource(const MateriaSource& materiaSource);
    MateriaSource&  operator=(const MateriaSource& materiaSource);
    ~MateriaSource(void);

    void        learnMateria(AMateria *);
    AMateria    *createMateria(const std::string& type);
};

#endif