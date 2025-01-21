/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:38:41 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/21 15:44:30 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	generate(t_data *data, t_map *map)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_printf("MLX init failed !\n");
		return (ft_mapclear(data->map));
	}
	if (generate_textures(data) == 1)
	{
		ft_printf("Textures failed !\n");
		ft_mapclear(data->map);
		close_win2(data);
	}
	data->win = mlx_new_window(data->mlx,
			map->len_line * 32, data->len_lst * 32, "so_long");
	if (!data->win)
	{
		ft_printf("Window failed !\n");
		ft_mapclear(data->map);
		close_win(data);
	}
}

void	find_xy(t_map *map, t_control *su)
{
	int	i;
	int	j;

	j = 0;
	while (map)
	{
		i = 0;
		while (map->line[i] != '\0')
		{
			if (map->line[i] == 'E')
			{
				su->x = i;
				su->y = j;
				return ;
			}
			i++;
		}
		j++;
		map = map->next;
	}
}

void	so_long(t_map **map, t_control **su)
{
	t_data	data;

	data.map = map;
	data.su = su;
	data.len_lst = ft_lstlen(*map);
	data.player.ni = 0;
	data.player.xe = -1;
	data.player.ye = -1;
	generate(&data, *map);
	print_map(&data, *data.map);
	mlx_key_hook(data.win, key_press, &data);
	mlx_hook(data.win, 17, 0, close_cross, &data);
	mlx_loop(data.mlx);
	return ;
}
