/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:58:19 by jojo              #+#    #+#             */
/*   Updated: 2025/01/24 19:39:46 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	t_data	*data;
	static struct timeval program_start;
	pthread_mutex_t mutex;

	data = ft_newdata();
	if (!data)
		return (msg_error(-1), 0);
	if (verif_init(ac, av, &data) == 1)
		return (0);
	//philo(data);
	gettimeofday(&program_start, NULL);
	pthread_mutex_init(&mutex, NULL);
	for (int i = 0; i < 1000; i++)
		print_state(1, "has taken a fork", program_start, mutex);
	clear_data(&data);
	pthread_mutex_destroy(&mutex);
}
