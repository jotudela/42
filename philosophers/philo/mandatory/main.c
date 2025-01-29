/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:58:19 by jojo              #+#    #+#             */
/*   Updated: 2025/01/29 17:25:16 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
et apres faire la routine + la fonction de verif si un philo meurt.
*/

int	main(int ac, char **av)
{
	t_main	*data;

	if (ft_verif(ac, av) == 1)
		return (0);
	data = ft_init(ac, av);
	ft_clear(&data, ft_atoi(av[1]));
}

/*
	//----- Pour obtenir les millisecondes --------------//

	gettimeofday(&fin, NULL);
	millisecondes = (fin.tv_sec - debut.tv_sec) * 1000;
    millisecondes += (fin.tv_usec - debut.tv_usec) / 1000;
	printf("Durée : %ld ms\n", millisecondes);
	usleep(2000);
	gettimeofday(&fin, NULL);
	millisecondes = (fin.tv_sec - debut.tv_sec) * 1000;
    millisecondes += (fin.tv_usec - debut.tv_usec) / 1000;
	printf("Durée : %ld ms\n", millisecondes);
*/