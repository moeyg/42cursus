#include <iostream>
#include <string>

#define RED    "\033[0;31m"
#define YELLOW "\033[0;33m"
#define RESET  "\033[0m"

int main(void)
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << RED << "# Print the address" << RESET << std::endl;
    std::cout << YELLOW << "string: " << &string << RESET << std::endl;
    std::cout << YELLOW << "stringPTR: " << stringPTR << RESET << std::endl;
    std::cout << YELLOW << "stringREF: " << &stringREF << RESET << std::endl << std::endl;

    std::cout << RED << "# Print the value" << RESET << std::endl;
    std::cout << YELLOW << "string: " << string << RESET << std::endl;
    std::cout << YELLOW << "stringPTR: " << *stringPTR << RESET << std::endl;
    std::cout << YELLOW << "string: " << stringREF << RESET << std::endl;

    return 0;
}