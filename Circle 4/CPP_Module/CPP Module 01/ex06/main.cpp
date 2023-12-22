#include "Harl.hpp"

int main(int argc, char *argv[])
{
    Harl    harl;

    if (argc != 2)
    {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        return 1;
    }

    std::string message(argv[1]);
    harl.complain(message);

    return 0;
}