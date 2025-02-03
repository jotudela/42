/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:05:31 by jojo              #+#    #+#             */
/*   Updated: 2025/01/31 19:33:23 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&pihlo->write_lock);
	pthread_mutex_lock(&philo->l_fork);
	printf("")
}

void	ft_think(t_main *data, t_philo *philo)
{
	pthread_mutex_lock(&pihlo->write_lock);
	gettimeofday(&data->update, NULL;)
	data->m_s = (data->update.tv_sec - data->start.tv_sec) * 1000;
    data->m_s += (data->start.tv_usec - data->update.tv_usec) / 1000;
	printf("%ld Philo %s is thinking\n", data->m_s, philo->id);
	pthread_mutex_unlock(&philo->write_lock);
}
