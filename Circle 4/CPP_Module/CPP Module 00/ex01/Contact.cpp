#include "Contact.hpp"

Contact::Contact() { }
Contact::~Contact() { }

void    Contact::setFirstName(const string &firstName) { this->firstName = firstName; }

void    Contact::setLastName(const string &lastName) { this->lastName = lastName; }

void    Contact::setNickname(const string &nickname) { this->nickname = nickname; }

void    Contact::setPhoneNumber(const string &phoneNumber) { this->phoneNumber = phoneNumber; }

void    Contact::setDarkestSecret(const string &darkestSecret) { this->darkestSecret = darkestSecret; }

string  Contact::getFirstName(void) const { return firstName; }

string  Contact::getLastName(void) const { return lastName; }

string  Contact::getNickname(void) const { return nickname; }

string  Contact::getPhoneNumber(void) const { return phoneNumber; }

string  Contact::getDarkestSecret(void) const { return darkestSecret; }
