/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:58:22 by jojo              #+#    #+#             */
/*   Updated: 2025/02/03 16:15:24 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stddef.h>
# include <stdint.h>

typedef struct s_philo
{
	pthread_t			philo;
	int						id;
	int						eating;
	int						meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int						num_of_philos;
	int						num_times_to_eat;
	int						dead;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	write_lock;
	volatile int	go;
}			t_philo;

typedef struct s_main
{
	int							dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	struct timeval start;
	struct timeval update;
	long	m_s;
	t_philo					*philos;
}			t_main;

/* Philo */
//void	philo(t_data data);

/* Utils */
int	ft_atoi(char *str);
void	msg_error(int type_error);
int	ft_verif(int ac, char **av);
t_main    *ft_init(int ac, char **av);
void *ft_calloc(size_t count, size_t size);
void    ft_clear(t_main **data, int nb);
void	ft_think(t_main *data, t_philo *philo);
void	ft_sleep(t_main *data, t_philo *philo);
void	philo(t_main *data);

#endif
