/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:51:33 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/24 13:32:17 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

static bool isGood( std::string str ){
    if (str == "DEBUG"
        or str == "INFO"
        or str == "WARNING"
        or str == "ERROR")
        return true;
    std::cerr << "Invalid argument." << std::endl;
    return false;
}

int main(int ac, char **av){
    if (ac >= 2){
        Harl harl;
        if (isGood((std::string)av[1]) == true){
            std::string l(av[1]);
            harl.complain(l);
        }
    }
}