/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:37:30 by dogpark           #+#    #+#             */
/*   Updated: 2023/12/18 12:14:28 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __PHONEBOOK_HPP__
# define __PHONEBOOK_HPP__

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
    PhoneBook();
    ~PhoneBook();
    void banner() const;
    void addContact();
    void searchContact() const;
    void displayContact(string contents) const;
    void displaySpecificContact() const;
};

# endif