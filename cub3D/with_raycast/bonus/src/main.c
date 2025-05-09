/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:40:10 by jojo              #+#    #+#             */
/*   Updated: 2025/05/06 19:04:02 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		(error("error: exec: arguments format './cub3D maps/.cub'\n"), exit(1));
	ft_is_good_format(av[1]);
	data = init_data();
	data->is_map = 0;
	data->is_paused = 0;
	data->is_game = 1;
	ft_init_data(&data, av[1]);
	cub3d(&data);
	free_data(&data);
}
