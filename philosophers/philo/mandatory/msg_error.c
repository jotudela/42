/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:58:25 by jojo              #+#    #+#             */
/*   Updated: 2025/01/24 18:58:26 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	msg_error(int type_error)
{
	if (type_error == -1)
		write(2, "Error\nCan't malloc data.", 25);
	else if (type_error == 0)
		write(2, "Error\nExec formar: ./philo [nb_pilos] [time_to_die] [time_to_eat] [time_to_sleep]", 82);
	else if (type_error == 1)
		write(2, "Error\nNumber of philos incorect !", 34);
	else if (type_error == 2)
		write(2, "Error\nTime to die incorect !", 29);
	else if (type_error == 3)
		write(2, "Error\nTime to eat incorect !", 29);
	else if (type_error == 4)
		write(2, "Error\nTime to sleep incorect !", 31);
	else if (type_error == 5)
		write(2, "Error\nNumber of max eat incorect !", 35);
}
