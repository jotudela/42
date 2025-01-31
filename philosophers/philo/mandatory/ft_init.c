/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:01:45 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/31 17:43:13 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void ft_clear(t_main **data, int nb)
{
    int i;

    if (!data || !*data)
        return;
    if ((*data)->philos)
    {
        i = 0;
        while (i < nb)
        {
            pthread_mutex_destroy(&((*data)->philos[i].l_fork));
            pthread_mutex_destroy(&((*data)->philos[i].r_fork));
            pthread_mutex_destroy(&((*data)->philos[i].write_lock));
            pthread_join(((*data)->philos[i].philo), NULL);
            i++;
        }
        free((*data)->philos);
        (*data)->philos = NULL;
    }
    pthread_mutex_destroy(&((*data)->dead_lock));
    pthread_mutex_destroy(&((*data)->meal_lock));
    pthread_mutex_destroy(&((*data)->write_lock));
    free(*data);
    *data = NULL;
}

static t_main  *alloc_data(char **av)
{
    t_main  *data;

    data = ft_calloc(1, sizeof(t_main));
    if (!data)
        return (NULL);
    data->philos = ft_calloc(ft_atoi(av[1]), sizeof(t_philo));
    if (!data->philos)
    {
        free(data);
        return (NULL);
    }
    return (data);
}

static void ft_init2(t_main *data)
{
    pthread_mutex_init(&data->dead_lock, NULL);
    pthread_mutex_init(&data->meal_lock, NULL);
    pthread_mutex_init(&data->write_lock, NULL);
    data->dead_flag = 0;
}

t_main  *ft_init(int ac, char **av)
{
    t_main  *data;
    int     i;

    data = alloc_data(av);
    if (!data)
        return (msg_error(6), NULL);
    i = 0;
    while (i < ft_atoi(av[1]))
    {
        data->philos[i].id = i + 1;
        data->philos[i].num_of_philos = ft_atoi(av[1]);
        data->philos[i].time_to_die = ft_atoi(av[2]);
        data->philos[i].time_to_eat = ft_atoi(av[3]);
        data->philos[i].time_to_sleep = ft_atoi(av[4]);
        data->philos[i].dead = 0;
        if (ac == 6)
            data->philos[i].num_times_to_eat = ft_atoi(av[5]);
        pthread_mutex_init(&data->philos[i].l_fork, NULL);
        pthread_mutex_init(&data->philos[i].r_fork, NULL);
        pthread_mutex_init(&data->philos[i].write_lock, NULL);
        i++;
    }
    ft_init2(data);
    return (data);
}
