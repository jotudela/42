/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:58:25 by jojo              #+#    #+#             */
/*   Updated: 2025/01/29 16:52:22 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	msg_error(int type_error)
{
	if (type_error == 0)
		write(2, "Error\nExec formar: ./philo [nb_pilos] [time_to_die] [time_to_eat] [time_to_sleep]", 82);
	else if (type_error == 1)
		write(2, "Error\nNumber of philos incorrect !", 35);
	else if (type_error == 2)
		write(2, "Error\nTime to die incorrect !", 30);
	else if (type_error == 3)
		write(2, "Error\nTime to eat incorrect !", 30);
	else if (type_error == 4)
		write(2, "Error\nTime to sleep incorrect !", 32);
	else if (type_error == 5)
		write(2, "Error\nNumber of eat incorrect !", 32);
	else if (type_error == 6)
		write(2, "Error\nCan't init data !", 24);
}
