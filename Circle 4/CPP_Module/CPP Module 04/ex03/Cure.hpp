#ifndef __CURE_HPP__
#define __CURE_HPP__

#define BLUE    "\033[0;34m"
#define PURPLE  "\033[0;35m"
#define RESET   "\033[0m"

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
public:
    Cure(void);
    Cure(const Cure &cure);
    Cure&   operator=(const Cure &cure);
    ~Cure(void);

    Cure*   clone(void) const;
    void    use(ICharacter& target);
};

#endif