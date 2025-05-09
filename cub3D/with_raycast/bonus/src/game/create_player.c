/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:26:10 by jotudela          #+#    #+#             */
/*   Updated: 2025/05/09 18:30:44 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_player(t_data *mlx, int tile_size)
{
	int	size;
	int	px;
	int	py;
	int	y;
	int	x;

	size = tile_size * 0.8;
	px = (1280 / 2) - (size / 2);
	py = (720 / 2) - (size / 2);
	y = 0;
	while (y < size)
	{
		x = -1;
		while (++x < size)
			mlx_pixel_put(mlx->mlx, mlx->win,
				px + x, py + y, 0xFF0000);
		y++;
	}
}
