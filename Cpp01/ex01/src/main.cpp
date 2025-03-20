/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:23:09 by jojo              #+#    #+#             */
/*   Updated: 2025/03/20 09:49:47 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int main(void)
{
    Zombie* z = zombieHorde(5, "David");
    
    if (!z) {
        std::cout << "Échec de l'allocation des zombies !" << std::endl;
        return 1;
    }

    for (int i = 0; i < 5; i++)
        z[i].announce();
    delete[] z;
    return 0;
}
