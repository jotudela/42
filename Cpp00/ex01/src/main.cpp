/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:56:15 by jojo              #+#    #+#             */
/*   Updated: 2025/03/18 13:43:44 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

int main(int ac, char **av)
{
    PhoneBook   Book;
    std::string str;

    (void)av;
    if (ac != 1)
    {
        std::cout << "Number of arguments not correct !" << std::endl;
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
        else if (str == "ADD")
            Book.ft_add();
        std::cout << "$> ";
        std::cin >> str;
    }
}
