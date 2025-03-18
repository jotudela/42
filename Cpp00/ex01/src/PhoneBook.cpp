/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:03:22 by jojo              #+#    #+#             */
/*   Updated: 2025/03/18 14:02:08 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

/**
 * @brief Construit tout les contacts
 * 
 */
PhoneBook::PhoneBook()
{
    count = 0;
}

/**
 * @brief Permet d'ajouter un contact
 * 
 */
void PhoneBook::ft_add()
{
    std::string input;
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "First Name: ";
    std::getline(std::cin, input);
    contacts[count].setFirstName(input);
    
    std::cout << "Last Name: ";
    std::getline(std::cin, input);
    contacts[count].setLastName(input);
    
    std::cout << "Nickname: ";
    std::getline(std::cin, input);
    contacts[count].setNickname(input);
    
    std::cout << "Phone Number: ";
    std::getline(std::cin, input);
    contacts[count].setPhoneNumber(input);
    
    std::cout << "Darkest Secret: ";
    std::getline(std::cin, input);
    contacts[count].setDarkestSecret(input);
    
    if (contacts[count].getFirstName().empty()
        || contacts[count].getLastName().empty()
        || contacts[count].getNickname().empty()
        || contacts[count].getPhoneNumber().empty()
        || contacts[count].getDarkestSecret().empty())
        return ;
    count = (count + 1) % 8;
}

/**
 * @brief Fonction pour tronquer si la chaine fait plus de 10 chars
 * 
 * @param str 
 * @return std::string 
 */
std::string PhoneBook::truncate(const std::string& str)
{
    char buffer[11];
    int i = 0;
    while (i < 10 && str[i] != '\0')
    {
        buffer[i] = str[i];
        i++;
    }
    if (str.length() > 10)
    {
        buffer[i] = '.';
        i++;
    }
    buffer[i] = '\0';
    return std::string(buffer);
}

/**
 * @brief Permet d'afficher un contact
 * 
 * @param index 
 */
void PhoneBook::print_contact(int index)
{
    if (contacts[index].getFirstName().empty()){
        std::cout << "Ce contact n'existe pas." << std::endl; 
        return ;
    }
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl
              << "Last Name: " << contacts[index].getLastName() << std::endl
              << "Nickname: " <<contacts[index].getNickname() << std::endl
              << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl
              << "Secret: " << contacts[index].getDarkestSecret() << std::endl;
}

/**
 * @brief Permet de chercher un contact
 * 
 */
void PhoneBook::ft_search()
{
    std::string str;
    int F_largueur = 11;
    std::cout << std::setw(4) << "Index" << "|"
              << std::setw(F_largueur) << "First Name" << "|"
              << std::setw(F_largueur) << "Last Name" << "|"
              << std::setw(F_largueur) << "Nickname" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    for (int i = 0; i < 8; i++)
    {
        std::cout << std::setw(5) << i + 1 << "|"
                  << std::setw(F_largueur) << truncate(contacts[i].getFirstName()) << "|"
                  << std::setw(F_largueur) << truncate(contacts[i].getLastName()) << "|"
                  << std::setw(F_largueur) << truncate(contacts[i].getNickname()) << std::endl;
    }
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << std::endl << "Quel contact voulez vous voir ? : ";
    std::cin >> str;
    std::stringstream number(str);
    int index;
    number >> index;
    if (index >= 1 && index <= 8)
        print_contact(index - 1);
    else
        std::cout << "Ce contact n'existe pas." << std::endl;
}


/**
 * @brief Permet de sortir du programme
 * 
 */
void    ft_exit(void)
{
    exit(EXIT_SUCCESS);
}
