/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:03:35 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/31 17:46:33 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//fonction ou tout mes thread passe
void    routine_philos(t_main *data, thread_t philo)
{

}

//fonction pour le main et regarder si tout les philo sont toujours vivant
void    routine_main(t_main *data);

void    *nothing(void *null)
{
    (void)null;
    return (NULL);
}

//fonction ou tout va se passer
void    philo(t_main *data)
{
    int i;

    i = 0;
    while (i < data->philos[i].num_of_philos)
        pthread_create(&data->philos[i++].philo, NULL, nothing, NULL);
    i = 0;
    while (i < data->philos[i].num_of_philos)
        routine_philos
}