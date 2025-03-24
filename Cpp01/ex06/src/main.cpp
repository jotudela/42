/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:51:33 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/24 14:10:40 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

static bool isGood( std::string& str )
{
    if (str == "DEBUG"
        or str == "INFO"
        or str == "WARNING"
        or str == "ERROR")
        return true;
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    return false;
}

int main(int ac, char **av){
    if (ac == 2){
        Harl harl;
        std::string str(av[1]);
        if (isGood(str) == true)
            harl.complain(str);
    }
}