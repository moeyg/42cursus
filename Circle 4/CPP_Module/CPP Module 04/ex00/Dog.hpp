#ifndef __DOG_HPP__
#define __DOG_HPP__

#include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog(void);
    Dog(const Dog& dog);
    Dog& operator=(const Dog& dog);
    ~Dog(void);

    void    makeSound(void) const;
};

#endif