/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:47:06 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/24 10:16:11 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lib.hpp"

int main(int ac, char **av)
{
    if (ac != 4){
        std::cerr << "Mauvais nombre d'arguments ! Format : [./sed] [file] [str1] [str2]" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string file(av[1]);
    std::string str1(av[2]);
    std::string str2(av[3]);

    replace_And_Create(file, str1, str2);
}
