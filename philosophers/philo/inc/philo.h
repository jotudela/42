/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:58:22 by jojo              #+#    #+#             */
/*   Updated: 2025/01/27 15:23:41 by jotudela         ###   ########.fr       */
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

typedef struct s_data
{
	int	nb_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	nb_of_eating;
	pthread_t	philo;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	write;
}			t_data;

/* Philo */
void	philo(t_data data);

/* Utils */
int	ft_atoi(char *str);
void	msg_error(int type_error);
int	verif_init(int ac, char **av, t_data **data);
t_data	*ft_newdata(int nb_philo);
void	clear_data(t_data **data);
int	print_state(int philo, char *state, pthread_mutex_t mutex);

#endif
