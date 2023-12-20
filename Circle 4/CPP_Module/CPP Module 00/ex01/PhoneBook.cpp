/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:37:22 by dogpark           #+#    #+#             */
/*   Updated: 2023/12/18 12:16:48 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : index(0), numOfContacts(0) { }
PhoneBook::~PhoneBook(void) { }

void    PhoneBook::banner(void) const
{
    cout << "______  _                         ______                _" << endl;
    cout << "| ___ \\| |                        | ___ \\              | |" << endl;
    cout << "| |_/ /| |__    ___   _ __    ___ | |_/ /  ___    ___  | | __" << endl;
    cout << "|  __/ | '_ \\  / _ \\ | '_ \\  / _ \\| ___ \\ / _ \\  / _ \\ | |/ /" << endl;
    cout << "| |    | | | || (_) || | | ||  __/| |_/ /| (_) || (_) ||   < " << endl;
    cout << "\\_|    |_| |_| \\___/ |_| |_| \\___|\\____/  \\___/  \\___/ |_|\\_\\" << endl;
}

void    PhoneBook::addContact(void)
{
    Contact contact;
    string input;

    cout << endl << "# ADD a contact" << endl << endl;

    cout << "  • Enter First name: "; 
    cin >> input; contacts[index].setFirstName(input);

    cout << "  • Enter Last name: ";
    cin >> input; contacts[index].setLastName(input);

    cout << "  • Enter Nickname: ";
    cin >> input; contacts[index].setNickname(input);

    cout << "  • Enter Phone number: ";
    cin >> input; contacts[index].setPhoneNumber(input);

    cout << "  • Enter Darkest secret: ";
    cin >> input; contacts[index].setDarkestSecret(input);

    numOfContacts++;
    index = (index + 1) % MAX_STORAGE;

    cout << endl << "Contact added successfully." << endl << endl << endl;
}

void    PhoneBook::searchContact(void) const
{
    if (numOfContacts == 0)
    {
        cout << endl << "PhoneBook is empty." << endl << endl << endl;
        return;
    }

    cout << endl << "# SEARCH a contact" << endl;
    cout << "┌───────┬────────────┬────────────┬────────────┐" << endl;
    cout << "│ Index │ First name │  Last name │  Nickname  │" << endl;
    cout << "├───────┼────────────┼────────────┼────────────┤" << endl; 

    for (int i = 0; i < MAX_STORAGE; i++)
    {
        if (i == numOfContacts) { break; }

        cout << "|   " << i + 1 << "   |";
        displayContact(contacts[i].getFirstName());
        displayContact(contacts[i].getLastName());
        displayContact(contacts[i].getNickname());
        cout << endl;
    }

    cout << "└───────┴────────────┴────────────┴────────────┘" << endl;

    displaySpecificContact();
}

void    PhoneBook::displayContact(string contents) const
{
    if (contents.length() > 10)
        contents = contents.substr(0, 9) + '.';
    cout << std::right;
    cout << " " << setw(10) << contents << " |";
}

void    PhoneBook::displaySpecificContact(void) const
{
    int idx;
    cout << "> Enter the index of the specific contact: "; cin >> idx;

    if (cin.fail())
    {
        cout << "Error: Invalid input." << endl;
        exit(1);
    }
    if (idx < 1 || idx > 8)
    {
        cout << endl << "Error: Invalid index number." << endl << endl;
        return;
    }

    cout << endl <<  "# Specific a contact" << endl << endl;
    idx -= 1;
    cout << "  • First name: " << contacts[idx].getFirstName() << endl;
    cout << "  • Last name: " << contacts[idx].getLastName() << endl;
    cout << "  • Nickname: " << contacts[idx].getNickname() << endl;
    cout << "  • Phone number: " << contacts[idx].getPhoneNumber() << endl;
    cout << "  • Darkest secret: " << contacts[idx].getDarkestSecret() << endl << endl << endl;
}
