#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void)
{
    PhoneBook phoneBook;
    
    while (true)
    {
        string command;
        
        phoneBook.banner();
        cout << endl << "# 80s PhoneBook" << endl;
        cout << "# Enter command: ADD, SEARCH, EXIT" << endl;
        cout << "> ";
        cin >> command;

        if (cin.fail()) { exit(1); };

        if (command == "EXIT")
        {
            cout << endl;
            exit(1);
        }
        else if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContact();
        else
            cerr << endl << "Error: Invalid commad." << endl << endl;
    }
    return 0;
}