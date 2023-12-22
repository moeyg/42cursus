#ifndef __PHONEBOOK_HPP__
#define __PHONEBOOK_HPP__

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using std::setw;

#define MAX_STORAGE 8
#define MAX_LENGTH  10

class PhoneBook
{
private:
    Contact contacts[MAX_STORAGE];
    int index;
    int numOfContacts;

public:
    PhoneBook(void);
    ~PhoneBook(void);
    void banner(void) const;
    void addContact(void);
    void searchContact(void) const;
    void displayContact(string contents) const;
    void displaySpecificContact(void) const;
};

# endif
