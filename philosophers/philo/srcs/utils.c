/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 02:17:41 by mmeuric           #+#    #+#             */
/*   Updated: 2025/02/11 16:06:15 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_verif(int argc, char **argv)
{
	int		i;
	long	nb;

	i = 0;
	if (argc != 5 && argc != 6)
	{
		write(2, "❌ Error 📖\n✅ Exec format: ./philo [nb_pilos] ", 52);
		return (msg_error("[time_to_die] [time_to_eat] [time_to_sleep]\n", 1));
	}
	while (++i < argc)
	{
		nb = ft_atoi(argv[i]);
		if (i == 1 && (nb < 1 || nb > MAX_PHILO))
			return (msg_error("❌ Error 👴\nNumber of philos incorrect !\n", 1));
		else if (i == 2 && (nb < 60 || nb > INT_MAX))
			return (msg_error("❌ Error 🕚\nTime to die incorrect !\n", 1));
		else if (i == 3 && (nb < 60 || nb > INT_MAX))
			return (msg_error("❌ Error 🕚\nTime to eat incorrect !\n", 1));
		else if (i == 4 && (nb < 60 || nb > INT_MAX))
			return (msg_error("❌ Error 🕚\nTime to sleep incorrect !\n", 1));
		else if (i == 5 && (nb < 0 || nb > INT_MAX))
			return (msg_error("❌ Error 🍝\nNumber of eat incorrect !\n", 1));
	}
	return (0);
}

void	ft_usleep(long ms)
{
	long	start;

	start = get_current_time();
	while (get_current_time() - start < ms)
		usleep(50);
}

int	ft_print_state(t_philo *philo, char *str)
{
	int		flag;
	long	time;

	pthread_mutex_lock(&philo->init->write_lock);
	pthread_mutex_lock(&philo->init->end);
	flag = philo->init->is_end;
	if (flag)
		return (pthread_mutex_unlock(&philo->init->end),
			pthread_mutex_unlock(&philo->init->write_lock), 1);
	pthread_mutex_unlock(&philo->init->end);
	time = get_current_time() - philo->times.first_time;
	printf("[%ldms] %d %s\n", time, philo->nb_print, str);
	pthread_mutex_unlock(&philo->init->write_lock);
	return (0);
}

int	msg_error(char *text, int digit)
{
	if (text)
		write(2, text, ft_strlen(text) + 1);
	return (digit);
}

void	ft_clean(t_init *init)
{
	int	i;

	i = 0;
	while (i < init->philo_count)
	{
		pthread_join(init->philos[i]->thread, NULL);
		pthread_mutex_lock(&init->philos[i]->meal_lock);
		pthread_mutex_unlock(&init->philos[i]->meal_lock);
		pthread_mutex_destroy(&init->philos[i]->meal_lock);
		pthread_mutex_lock(&init->fork[i]);
		pthread_mutex_unlock(&init->fork[i]);
		pthread_mutex_destroy(&init->fork[i]);
		free(init->philos[i]);
		i++;
	}
	free(init->fork);
	free(init->philos);
	pthread_mutex_destroy(&init->end);
	pthread_mutex_destroy(&init->write_lock);
}
