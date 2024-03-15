#ifndef __WRONGANIMAL_HPP__
#define __WRONGANIMAL_HPP__

#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define PURPLE  "\033[0;35m"
#define RESET   "\033[0m"

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
    std::string type;

public:
    WrongAnimal(void);
    WrongAnimal(const WrongAnimal& wrongAnimal);
    WrongAnimal& operator=(const WrongAnimal& wrongAnimal);
    virtual ~WrongAnimal(void);

    void        makeSound(void) const;
    std::string getType(void) const;
};

#endif