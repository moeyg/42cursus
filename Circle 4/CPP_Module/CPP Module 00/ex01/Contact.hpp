/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:37:12 by dogpark           #+#    #+#             */
/*   Updated: 2023/12/18 11:59:50 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONTACT_HPP__
#define __CONTACT_HPP__

#include <string>

using std::string;

class Contact
{
private:
    string firstName;
    string lastName;
    string nickname;
    string phoneNumber;
    string darkestSecret;

public:
    Contact();
    ~Contact();
    void    setFirstName(const string &firstName);
    void    setLastName(const string &lastName);
    void    setNickname(const string &nickname);
    void    setPhoneNumber(const string &phoneNumber);
    void    setDarkestSecret(const string &darkestSecret);
    string  getFirstName(void) const;
    string  getLastName(void) const;
    string  getNickname(void) const;
    string  getPhoneNumber(void) const;
    string  getDarkestSecret(void) const;
};

#endif
