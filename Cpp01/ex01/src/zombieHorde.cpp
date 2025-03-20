/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 09:28:11 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/20 09:43:55 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (N <= 0)
        return NULL;

    Zombie* horde = new Zombie[N];

    for (int i = 0; i < N; i++) {
        horde[i].setName(name);
    }
    return horde;
}
