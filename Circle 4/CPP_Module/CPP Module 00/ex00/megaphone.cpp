#include <iostream>
#include <cctype>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            for (int j = 0; argv[i][j] != '\0'; j++)
            {
                std::cout << static_cast<unsigned char>(std::toupper(argv[i][j]));
            }
        }
        std::cout << std::endl;
    }
    return 0;
}