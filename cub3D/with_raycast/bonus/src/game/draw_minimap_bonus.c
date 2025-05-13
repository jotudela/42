/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:58:52 by jotudela          #+#    #+#             */
/*   Updated: 2025/05/13 11:26:57 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

void	put_pixel_to_final_image(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x < 20 || x >= 300 || y < 20 || y >= 150)
		return ;
	if (!img || !img->addr || x < 0 || y < 0
		|| x >= img->img_x || y >= img->img_y)
		return ;
	dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_square_to_final_image(t_image *img, int x, int y, int size)
{
	int	i;
	int	j;
	int	px;
	int	py;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			px = x + j;
			py = y + i;
			if (px < 20 || px >= 300 || py < 20 || py >= 150)
				continue ;
			if (i == 0 || i == size - 1 || j == 0 || j == size - 1)
				put_pixel_to_final_image(img, px, py, 0x444444);
			else
				put_pixel_to_final_image(img, px, py, img->color);
		}
	}
}

void	draw_player2(t_image *img, int tile_size)
{
	int	player_size;
	int	px;
	int	py;

	player_size = tile_size * 0.8;
	px = 100 - player_size / 2;
	py = 100 - player_size / 2;
	img->color = 0xFF0000;
	draw_square_to_final_image(img, px, py, player_size);
}

int	which_color(t_data *data, char **map, int y, int x)
{
	if (map[y][x] == '1')
		data->img.color = 0xFFFFFF;
	else if (map[y][x] == '0')
		data->img.color = 0x000000;
	else
		return (-1);
	return (0);
}

void	render_map_to_final_image(t_data *data, char **map, int tile_size)
{
	int	x;
	int	y;
	int	offset_x;
	int	offset_y;

	y = 0;
	offset_x = 100 - (int)(data->player.x * tile_size);
	offset_y = 100 - (int)(data->player.y * tile_size);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (which_color(data, map, y, x) == -1)
			{
				x++;
				continue ;
			}
			draw_square_to_final_image(&data->img, x * tile_size + offset_x,
				y * tile_size + offset_y, tile_size);
			x++;
		}
		y++;
	}
	draw_player2(&data->img, tile_size);
}
