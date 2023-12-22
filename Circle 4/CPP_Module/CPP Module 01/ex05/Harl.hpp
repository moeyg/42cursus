#ifndef __HARL_HPP__
#define __HARL_HPP__

#include <iostream>

#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLACK  "\033[0;30m"
#define RESET   "\033[0m"

class Harl
{
private:
    void    debug(void);
    void    info(void);
    void    warning(void);
    void    error(void);

public:
    Harl(void);
    ~Harl(void);
    void    complain(std::string level);
};

#endif