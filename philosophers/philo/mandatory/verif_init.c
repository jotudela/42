/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:58:12 by jojo              #+#    #+#             */
/*   Updated: 2025/01/27 15:17:21 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	size_args(int ac)
{
	if (ac < 2)
		return (1);
	else if (ac > 1 && ac < 5)
		return (1);
	else if (ac == 5 || ac == 6)
		return (0);
	else
		return (1);
}

static int	ft_init(int ac, char **av, t_data *data)
{
	data->nb_philo = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nb_of_eating = ft_atoi(av[5]);
	if (data->nb_philo <= 0)
		return (clear_data(&data), 1);
	else if (data->time_die <= 0)
		return (clear_data(&data), 2);
	else if (data->time_eat <= 0)
		return (clear_data(&data), 3);
	else if (data->time_sleep <= 0)
		return (clear_data(&data), 4);
	else if (ac == 6 && data->nb_of_eating < 0)
		return (clear_data(&data), 5);

	return (0);
}

int	verif_init(int ac, char **av, t_data **data)
{
	int	type_error;

	if (size_args(ac) == 1)
		return (msg_error(0), 1);
	type_error = ft_init(ac, av, *data);
	if (type_error != 0)
		return (msg_error(type_error), 1);
	return (0);
}
