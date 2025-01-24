/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:05:31 by jojo              #+#    #+#             */
/*   Updated: 2025/01/24 19:39:29 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void print_state(int philo, char *state, struct timeval program_start, pthread_mutex_t mutex)
{
    struct timeval current;
    long ms;

    pthread_mutex_lock(&mutex);
    gettimeofday(&current, NULL);
    ms = (current.tv_sec - program_start.tv_sec) * 1000 +
         (current.tv_usec - program_start.tv_usec) / 1000;
    printf("%ld Philo %d %s\n", ms, philo, state);
    pthread_mutex_unlock(&mutex);
}
