/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:58:52 by jotudela          #+#    #+#             */
/*   Updated: 2025/05/12 19:01:50 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	put_pixel_to_final_image(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x < 20 || x >= 300 || y < 20 || y >= 150)
		return ;
	if (!img || !img->addr || x < 0 || y < 0 || x >= img->img_x || y >= img->img_y)
		return ;
	dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_square_to_final_image(t_image *img, int x, int y, int size, int color)
{
	int	i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			int px = x + j;
			int py = y + i;

			if (px < 20 || px >= 300 || py < 20 || py >= 150)
				continue;

			if (i == 0 || i == size - 1 || j == 0 || j == size - 1)
				put_pixel_to_final_image(img, px, py, 0x444444); // bordures
			else
				put_pixel_to_final_image(img, px, py, color);
		}
	}
}

void	render_map_to_final_image(t_data *data, char **map, int tile_size)
{
	int		x, y;
	int		screen_cx = 100;
	int		screen_cy = 100;
	int		offset_x = screen_cx - (int)(data->player.x * tile_size);
	int		offset_y = screen_cy - (int)(data->player.y * tile_size);
	int		color;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				color = 0xFFFFFF;
			else if (map[y][x] == '0')
				color = 0x000000;
			else
			{
				x++;
				continue;
			}
			draw_square_to_final_image(&data->img, x * tile_size + offset_x,
				y * tile_size + offset_y, tile_size, color);
			x++;
		}
		y++;
	}
    // ✅ Ajout de l'affichage du joueur
	int player_size = tile_size * 0.8;
	int px = screen_cx - player_size / 2;
	int py = screen_cy - player_size / 2;

	draw_square_to_final_image(&data->img, px, py, player_size, 0xFF0000);
}
