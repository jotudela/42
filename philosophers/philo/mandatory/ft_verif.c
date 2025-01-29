/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:58:12 by jojo              #+#    #+#             */
/*   Updated: 2025/01/29 15:23:41 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	size_args(int ac)
{
	if (ac < 2)
		return (1);
	else if (ac > 1 && ac < 5)
		return (1);
	else if (ac == 5 || ac == 6)
		return (0);
	else
		return (1);
}

static int	is_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

/*
	0 pas le bon nombre d'arguments
	1 nombre de philos
	2 time_to_die
	3 time_to_eat
	4 time to_sleep
	5 nb of eat
*/

int	ft_verif(int ac, char **av)
{
	int	nb;

	if (size_args(ac) == 1)
		return (msg_error(0), 1);
	nb = ft_atoi(av[1]);
	if (nb <= 0 || nb > 200 || is_char(av[1]) == 1)
		return (msg_error(1), 1);
	nb = ft_atoi(av[2]);
	if (nb <= 0 || is_char(av[2]) == 1)
		return (msg_error(2), 1);
	nb = ft_atoi(av[3]);
	if (nb <= 0 || is_char(av[3]) == 1)
		return (msg_error(3), 1);
	nb = ft_atoi(av[4]);
	if (nb <= 0 || is_char(av[4]) == 1)
		return (msg_error(4), 1);
	if (ac == 6)
	{
		nb = ft_atoi(av[5]);
		if (nb < 0 || is_char(av[5]) == 1)
			return (msg_error(5), 1);
	}
	return (0);
}
