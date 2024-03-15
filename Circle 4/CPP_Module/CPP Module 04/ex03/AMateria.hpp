#ifndef __AMATERIA_HPP__
#define __AMATERIA_HPP__

#include "ICharacter.hpp"
#include <iostream>
#include <string>

class AMateria
{
protected:
    std::string type;

public:
    AMateria(void);
    AMateria(const std::string& type);
    AMateria(const AMateria &aMateria);
    AMateria&   operator=(const AMateria& aMateria);
    virtual ~AMateria(void);

    const std::string&  getType(void) const;
    virtual AMateria*   clone(void) const = 0;
    virtual void        use(ICharacter& target);
};

#endif