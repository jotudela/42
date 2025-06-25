/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:13:51 by jotudela          #+#    #+#             */
/*   Updated: 2025/06/25 14:36:11 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static void	init_player2(t_data **data, int x, int y)
{
	if ((*data)->map->tab[y][x] == 'E')
	{
		(*data)->player.dirx = 1;
		(*data)->player.diry = 0;
		(*data)->player.planex = 0;
		(*data)->player.planey = 0.66;
	}
}

static void	init_player(t_data **data, int x, int y)
{
	if ((*data)->map->tab[y][x] == 'N')
	{
		(*data)->player.dirx = 0;
		(*data)->player.diry = -1;
		(*data)->player.planex = 0.66;
		(*data)->player.planey = 0;
	}
	if ((*data)->map->tab[y][x] == 'S')
	{
		(*data)->player.dirx = 0;
		(*data)->player.diry = 1;
		(*data)->player.planex = -0.66;
		(*data)->player.planey = 0;
	}
	if ((*data)->map->tab[y][x] == 'W')
	{
		(*data)->player.dirx = -1;
		(*data)->player.diry = 0;
		(*data)->player.planex = 0;
		(*data)->player.planey = -0.66;
	}
	init_player2(data, x, y);
	(*data)->map->tab[y][x] = '0';
}

static void	generate(t_data **data)
{
	(*data)->player.x = (*data)->map->map_x + 0.5;
	(*data)->player.y = (*data)->map->map_y + 0.5;
	init_player(data, (*data)->map->map_x, (*data)->map->map_y);
	(*data)->mlx = mlx_init();
	if (!(*data)->mlx)
		(free_data(data), error("Error\nMLX inti failed !\n"), exit(1));
	if (mlx_get_screen_size((*data)->mlx,
			&(*data)->img.img_x, &(*data)->img.img_y) == 1)
		(free_data(data), error("Error\nGet screen size failed !\n"), exit(1));
	(*data)->img.img_x /= 3;
	(*data)->img.img_y /= 3;
	if (generate_textures(*data) == -1)
		(free_data(data), error("Error\nFailed "
				"to generate textures !\n"), exit(1));
	(*data)->win = mlx_new_window((*data)->mlx,
			(*data)->img.img_x, (*data)->img.img_y, "cub3D_bonus");
	if (!(*data)->win)
		(free_data(data), error("Error\nGenerate "
				"new window failed !\n"), exit(1));
	(*data)->player.move = 0.05;
	(*data)->player.rot = 0.05;
	create_img_background(data);
}

static void	do_game(t_data **data)
{
	mlx_loop_hook((*data)->mlx, game_loop, *data);
	mlx_loop((*data)->mlx);
}

void	cub3d(t_data **data)
{
	generate(data);
	mlx_hook((*data)->win, 2, 1L << 0, key_press, *data);
	mlx_hook((*data)->win, 3, 1L << 1, key_release, *data);
	mlx_hook((*data)->win, 17, 0, close_cross, *data);
	do_game(data);
}
