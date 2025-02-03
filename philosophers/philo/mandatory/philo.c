/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:03:35 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/03 16:27:34 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/**
 * @brief Fonction pour passer tout mes philos.
 * 
 * @param data 
 */
void *routine_philos(void *arg)
{
    t_philo     *philo;
    t_main      *data;

    philo = (t_philo *)arg;
    data = (t_main *)arg;
    while (!philo->go){}
    ft_sleep(data, data->philos);
    ft_think(data, data->philos);
    return (NULL);
}

/**
 * @brief Fonction pour verifier tout les philos.
 * 
 * @param data 
 */
void    routine_main(t_main *data)
{
    (void)data;
    printf("yo du main\n");
}

/**
 * @brief Focntion pour init le reste.
 * 
 * @param data 
 */
void philo(t_main *data)
{
    int i;

    i = 0;
    data->philos[0].go = 0;
    while (i < data->philos[0].num_of_philos)
    {
        pthread_create(&data->philos[i].philo, NULL, routine_philos, &data->philos[i]);
        i++;
    }
    gettimeofday(&data->start, NULL);
    data->philos[0].go = 1;
    routine_main(data);
}
