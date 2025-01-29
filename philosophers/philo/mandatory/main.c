/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:58:19 by jojo              #+#    #+#             */
/*   Updated: 2025/01/29 17:06:35 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
et apres faire la routine + la fonction de verif si un philo meurt.
*/

int	main(int ac, char **av)
{
	t_main	*data;
	int	i = 0;

	if (ft_verif(ac, av) == 1)
		return (0);
	data = ft_init(ac, av);
	ft_clear(&data, ft_atoi(av[1]));
}
