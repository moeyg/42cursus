#include "StreamEditor.hpp"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << RED << "Error: Invalid number of arguments." << RESET << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    StreamEditor streamEditor(filename, s1, s2);

    if (!streamEditor.processFile()) { return 1; }

    return 0;
}
