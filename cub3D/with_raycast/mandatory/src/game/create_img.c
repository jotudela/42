/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:38:32 by jotudela          #+#    #+#             */
/*   Updated: 2025/06/25 13:05:12 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	put_pixel_to_image2(t_image *img, int x, int y, int color)
{
	char	*dst;
	int		real_y;

	if (x < 0 || x >= img->img_x || y < 0 || y >= img->img_y)
		return ;
	real_y = y;
	if (img->size_line < 0)
		real_y = img->img_y - 1 - y;
	dst = img->addr
		+ (real_y * abs(img->size_line) + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_walls(t_data *data, int x, t_tex_info *tex, t_raycast r)
{
	int	y;

	y = r.drawstart;
	while (y < r.drawend)
	{
		r.d = y * 256 - data->img.img_y * 128 + r.lineheight * 128;
		r.texy = ((r.d * tex->height) / r.lineheight) / 256;
		if (r.texy < 0)
			r.texy = 0;
		if (r.texy >= tex->height)
			r.texy = tex->height - 1;
		r.color = *(unsigned int *)(tex->addr
				+ (r.texy * tex->size_line + r.texx
					* (tex->bits_per_pixel / 8)));
		put_pixel_to_image2(&data->img, x, y, r.color);
		y++;
	}
}

static void	put_pixel(char *data, int color, int i)
{
	data[i + 0] = (color & 0x000000FF);
	data[i + 1] = (color & 0x0000FF00) >> 8;
	data[i + 2] = (color & 0x00FF0000) >> 16;
}

void	ft_draw_img(t_data **data)
{
	int	y;
	int	x;
	int	i;
	int	color;

	y = 0;
	while (y < (*data)->img.img_y)
	{
		x = 0;
		while (x < (*data)->img.img_x)
		{
			if (y < (*data)->img.img_y / 2)
				color = (*data)->img.c;
			else
				color = (*data)->img.f;
			i = (y * (*data)->img.size_line)
				+ (x * ((*data)->img.bits_per_pixel / 8));
			put_pixel((*data)->img.addr, color, i);
			x++;
		}
		y++;
	}
}

void	create_img_background(t_data **data)
{
	(*data)->img.img_ptr = mlx_new_image((*data)->mlx,
			(*data)->img.img_x, (*data)->img.img_y);
	if (!(*data)->img.img_ptr)
		(free_data(data), error("Error\nCreate new image failed !\n"), exit(1));
	(*data)->img.addr = mlx_get_data_addr((*data)->img.img_ptr,
			&(*data)->img.bits_per_pixel,
			&(*data)->img.size_line,
			&(*data)->img.endian);
	if (!(*data)->img.addr)
		(free_data(data),
			error("Error\nGet addr of image failed !\n"), exit(1));
	ft_draw_img(data);
}
