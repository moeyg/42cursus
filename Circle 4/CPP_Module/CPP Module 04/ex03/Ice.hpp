#ifndef __ICE_HPP__
#define __ICE_HPP__

#define BLUE    "\033[0;34m"
#define PURPLE  "\033[0;35m"
#define RESET   "\033[0m"

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice(void);
    Ice(const Ice& ice);
    Ice&    operator=(const Ice &ice);
    ~Ice(void);

    Ice     *clone(void) const;
    void    use(ICharacter& target);
};

#endif