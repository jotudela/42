/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:03:22 by jojo              #+#    #+#             */
/*   Updated: 2025/03/17 16:39:04 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/phonebook.hpp"

PhoneBook::PhoneBook()
{
    
}

PhoneBook::~PhoneBook()
{
    
}

void    PhoneBook::ft_add(std::string tab[7])
{
    (void)tab;
}

void    PhoneBook::ft_search(void)
{
    int F_largueur = 14, i = 1, j;
    std::cout << std::setw(F_largueur * 4) << std::right << "-----------------------------------------------" << std::endl;
    std::cout << " ";
    std::cout << std::setw(F_largueur) << std::right << "|index|";
    std::cout << std::setw(F_largueur) << std::right << "first name|";
    std::cout << std::setw(F_largueur) << std::right << "last name|";
    std::cout << std::setw(F_largueur) << std::right << "nickname|" << std::endl;
    std::cout << std::setw(F_largueur * 4) << std::right << "-----------------------------------------------" << std::endl;
    while (i < 9)
    {
        std::cout << std::setw(F_largueur - 3) << std::right << "|  " << i << "  |";
        j = 0;
        while (j < 3)
        {
            std::cout << std::setw(F_largueur) << std::right << "|";
            j++;
        }
        std::cout << std::setw(F_largueur * 4) << std::right << std::endl << "-----------------------------------------------" << std::endl;
        i++;
    }
}

void    ft_exit(void)
{
    std::cout << "Bye !" << std::endl;
    exit(EXIT_SUCCESS);
}
