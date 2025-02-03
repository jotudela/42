/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:05:31 by jojo              #+#    #+#             */
/*   Updated: 2025/02/03 15:06:27 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/**
 * @brief Fonction pour faire manger les philos.
 * 
 * @param philo 
 */
void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->write_lock);
	pthread_mutex_lock(&philo->l_fork);
	printf("");
}

/**
 * @brief Fonction pour faire pense les philos.
 * 
 * @param data 
 * @param philo 
 */
void	ft_think(t_main *data, t_philo *philo)
{
	pthread_mutex_lock(&philo->write_lock);
	gettimeofday(&data->update, NULL);
	data->m_s = (data->update.tv_sec - data->start.tv_sec) * 1000;
    data->m_s += (data->start.tv_usec - data->update.tv_usec) / 1000;
	printf("%ld Philo %i is thinking\n", data->m_s, philo->id);
	pthread_mutex_unlock(&philo->write_lock);
}

/**
 * @brief Fonction pour dormir les philos.
 * 
 * @param data 
 * @param philo 
 */
void	ft_sleep(t_main *data, t_philo *philo)
{
	pthread_mutex_lock(&philo->write_lock);
	usleep(philo->time_to_sleep * 1000);
	gettimeofday(&data->update, NULL);
	data->m_s = (data->update.tv_sec - data->start.tv_sec) * 1000;
    data->m_s += (data->start.tv_usec - data->update.tv_usec) / 1000;
	printf("%ld Philo %i is sleeping\n", data->m_s, philo->id);
	pthread_mutex_unlock(&philo->write_lock);
}
