#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
    {
        Dog* patrasche = new Dog();
        Cat* doraemon = new Cat();

        std::cout << BLACK << "\n[ Dog ]" << RESET << std::endl;
        for (int i = 0; i < 3; i++)
        {
            std::cout << BLUE << "Thinking..." << RESET;
            patrasche->getBrain().setIdea(i, "Patrasche");
        }
        std::cout << std::endl;

        std::cout << BLACK << "\n[ Cat ]" << RESET << std::endl;
        for (int i = 0; i < 4; i++)
        {
            std::cout << YELLOW << "Thinking..." << RESET;
            doraemon->getBrain().setIdea(i, "Doraemon");
        }
        std::cout << std::endl << std::endl;

        patrasche->makeSound();
        std::cout << BLUE << "Patrasche: I think my name is ";
        std::cout << patrasche->getBrain().getIdea(1) << RESET << std::endl;

        doraemon->makeSound();
        std::cout << YELLOW << "Doraemon: I think my name is ";
        std::cout << doraemon->getBrain().getIdea(1) << RESET << std::endl << std::endl;

        delete patrasche;
        delete doraemon;
    }

    {
        std::cout << BLACK << "\n[ Animal array ]" << RESET << std::endl;
        Animal* animals[4] = {new Dog(), new Cat(), new Dog(), new Cat()};
        std::cout << std::endl;
        
        std::cout << BLACK << "[ Animal array delete ] " << RESET << std::endl;
        for (int i = 0; i < 4; i++)
            delete animals[i];
        
    }

    return 0;
}