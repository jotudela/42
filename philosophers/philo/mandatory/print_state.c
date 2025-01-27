/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:05:31 by jojo              #+#    #+#             */
/*   Updated: 2025/01/27 14:19:47 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (write(2, "gettimeofday() error\n", 22), 0);
	return (time.tv_sec * 1000 + time.tv_sec / 1000);
}

static size_t	ft_usleep(size_t m_s)
{
	size_t	start;
	size_t	tmp;

	start = get_current_time();
	tmp = 0;
	while ((tmp - start) < m_s)
	{
		tmp = get_current_time();
		usleep(m_s);
	}
	return (tmp);
}

int	print_state(int philo, char *state, pthread_mutex_t mutex)
{
	pthread_mutex_lock(&mutex);
	printf("%zu Philo %d %s\n", ft_usleep(200), philo, state);
	pthread_mutex_unlock(&mutex);
	pthread_mutex_destroy(&mutex);	
	return (0);
}
