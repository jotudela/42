/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:58:19 by jojo              #+#    #+#             */
/*   Updated: 2025/01/31 19:19:53 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
et apres faire la routine + la fonction de verif si un philo meurt.
*/

void	one_philo(void)
{
	write(1, "0 Philo 1 has taken a fork\n", 28);
	write(1, "0 Philo 1 died\n", 16);
}

int	main(int ac, char **av)
{
	t_main	*data;

	if (ft_verif(ac, av) == 1)
		return (0);
	data = ft_init(ac, av);
	if (data->philos[0].num_of_philos == 1)
	{
		one_philo();
		ft_clear(&data, ft_atoi(av[1]));
		return (0);
	}
	philo(data);
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