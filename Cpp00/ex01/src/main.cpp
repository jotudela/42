/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:56:15 by jojo              #+#    #+#             */
/*   Updated: 2025/03/17 16:36:00 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/phonebook.hpp"

int main(int ac, char **av)
{
    PhoneBook   Book;
    std::string str;

    (void)av;
    if (ac != 1)
    {
        std::cerr << "Number of arguments not correct !" << std::endl;
        return (1);
    }
    std::cout << "$> ";
    std::cin >> str;
    if (str == "EXIT")
        ft_exit();
    while (str != "EXIT")
    {
        if (str == "EXIT")
            ft_exit();
        else if (str == "SEARCH")
            Book.ft_search();
        std::cout << "$> ";
        std::cin >> str;
    }
}