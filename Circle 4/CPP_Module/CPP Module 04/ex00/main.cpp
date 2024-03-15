#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    std::cout << BLACK << "[ Animal ]" << RESET << std::endl;
    {
        const Animal* animal = new Animal();
        const Animal* cat = new Cat();
        const Animal* dog = new Dog();

        std::cout << animal->getType() << ": ";
        animal->makeSound();
        std::cout << cat->getType() << ": ";
        cat->makeSound();
        std::cout << dog->getType() << ": ";
        dog->makeSound();

        delete animal;
        delete cat;
        delete dog;
    }

    std::cout << std::endl << BLACK << "[ Wrong Animal ]" << RESET << std::endl;
    {
        const WrongAnimal* wrongAnimal = new WrongAnimal();
        const WrongAnimal* wrongCat = new WrongCat();

        std::cout << wrongAnimal->getType() << ": ";
        wrongAnimal->makeSound();
        std::cout << wrongCat->getType() << ": ";
        wrongCat->makeSound();

        delete wrongAnimal;
        delete wrongCat;
    }

    return 0;
}