/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:19:13 by jotudela          #+#    #+#             */
/*   Updated: 2025/05/09 14:22:42 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	put_pixel_to_image(t_minimap *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= 1280 * 30 || y >= 720 * 30)
		return ;
	dst = img->m_pixels + (y * img->m_line_length
			+ x * (img->m_bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_square_to_image(t_minimap *img, int x, int y, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i == 0 || i == size - 1 || j == 0 || j == size - 1)
				put_pixel_to_image(img, x + j, y + i, 0x444444);
			else
				put_pixel_to_image(img, x + j, y + i, img.color);
			j++;
		}
		i++;
	}
}

void	render_map_to_image(t_minimap *img, char **map, int tile_size)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				img.color = 0xFFFFFF;
			else if (map[y][x] == '0')
				img.color = 0x000000;
			else
				continue ;
			draw_square_to_image(img, x * tile_size, y * tile_size,
				tile_size);
			x++;
		}
		y++;
	}
}

void	create_minimap(t_data **data)
{
	int	tile_size;
	int	image_width;
	int	image_height;

	tile_size = 30;
	image_width = 1280;
	image_height = 720;
	(*data)->minimap.m_img_ptr = mlx_new_image((*data)->mlx,
			image_width, image_height);
	(*data)->minimap.m_pixels = mlx_get_data_addr(
			(*data)->minimap.m_img_ptr,
			&(*data)->minimap.m_bits_per_pixel,
			&(*data)->minimap.m_line_length,
			&(*data)->minimap.m_endian);
	render_map_to_image(&(*data)->minimap, (*data)->map->tab, tile_size);
}
