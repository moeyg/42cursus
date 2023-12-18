/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:37:09 by dogpark           #+#    #+#             */
/*   Updated: 2023/12/18 12:00:38 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() { }
Contact::~Contact() { }

void    Contact::setFirstName(const string &firstName) { this->firstName = firstName; }

void    Contact::setLastName(const string &lastName) { this->lastName = lastName; }

void    Contact::setNickname(const string &nickname) { this->nickname = nickname; }

void    Contact::setPhoneNumber(const string &phoneNumber) { this->phoneNumber = phoneNumber; }

void    Contact::setDarkestSecret(const string &darkestSecret) { this->darkestSecret = darkestSecret; }

string  Contact::getFirstName() const { return firstName; }

string  Contact::getLastName() const { return lastName; }

string  Contact::getNickname() const { return nickname; }

string  Contact::getPhoneNumber() const { return phoneNumber; }

string  Contact::getDarkestSecret() const { return darkestSecret; }