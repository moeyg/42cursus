#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define RESET   "\033[0m"

#include <iostream>
#include <string>

class Brain
{
private:
    std::string ideas[100];

public:
    Brain(void);
    Brain(const Brain& brain);
    Brain&  operator=(const Brain& brain);
    ~Brain(void);

    std::string getIdea(int index)  const;
    void        setIdea(int index, std::string idea);
};

#endif