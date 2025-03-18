/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:34:32 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/18 13:43:29 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

/**
 * @brief Permet de set le prenom
 * 
 * @param name 
 */
void Contact::setFirstName(const std::string &name)
{
    first_name = name;
}

/**
 * @brief Permet de set le nom
 * 
 * @param name 
 */
void Contact::setLastName(const std::string &name)
{
    last_name = name;
}

/**
 * @brief Permet de set le surnom
 * 
 * @param nick 
 */
void Contact::setNickname(const std::string &nick)
{
    nickname = nick;
}

/**
 * @brief Permet de set le num de tel
 * 
 * @param number 
 */
void Contact::setPhoneNumber(const std::string &number)
{
    phone_number = number;
}

/**
 * @brief Permet de set le un sombre secret
 * 
 * @param secret 
 */
void Contact::setDarkestSecret(const std::string &secret)
{
    darkest_secret = secret;
}

/**
 * @brief Construit un nouveau coontact avec tout initialise a RIEN
 * 
 */
Contact::Contact()
{
    setFirstName("");
    setLastName("");
    setNickname("");
    setPhoneNumber("");
    setDarkestSecret("");
}

/**
 * @brief Permet de recuperer le prenom
 * 
 * @return std::string 
 */
std::string Contact::getFirstName() const
{
    return first_name;
}

/**
 * @brief Permet de recuperer le nom
 * 
 * @return std::string 
 */
std::string Contact::getLastName() const
{
    return last_name;
}

/**
 * @brief Permet de recuperer le surnom
 * 
 * @return std::string 
 */
std::string Contact::getNickname() const
{
    return nickname;
}

/**
 * @brief Permet de recuperer le num de tel
 * 
 * @return std::string 
 */
std::string Contact::getPhoneNumber() const
{
    return phone_number;
}

/**
 * @brief Permet de recuperer le sombre secret
 * 
 * @return std::string 
 */
std::string Contact::getDarkestSecret() const
{
    return darkest_secret;
}
