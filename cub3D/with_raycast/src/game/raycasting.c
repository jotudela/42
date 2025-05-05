/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:04:45 by jotudela          #+#    #+#             */
/*   Updated: 2025/05/05 18:36:16 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int get_pixel_color(t_image *img, int x, int y)
{
	char *pixel;

	if (x < 0 || x >= img->img_x || y < 0 || y >= img->img_y)
		return (0); // ou couleur par défaut

	pixel = img->b_addr + (y * img->b_size_line + x * (img->b_bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
}

static void put_pixel_to_image2(t_image *img, int x, int y, int color)
{
    char *dst;

    if (x < 0 || x >= img->img_x || y < 0 || y >= img->img_y)
        return;
    dst = img->f_addr + (y * img->f_size_line + x * (img->f_bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

static void copy_image(t_image *img)
{
	for (int y = 0; y < img->img_y; y++)
	{
		for (int x = 0; x < img->img_x; x++)
		{
			int color = get_pixel_color(img, x, y);
			put_pixel_to_image2(img, x, y, color);
		}
	}
}

void draw_vertical_line(t_data *data, int x, int drawStart, int drawEnd, int color)
{
    for (int y = drawStart; y <= drawEnd; y++)
        put_pixel_to_image2(&data->img, x, y, color);
}

void raycasting(t_data *data)
{
    data->img.f_img_ptr = mlx_new_image(data->mlx, data->img.img_x, data->img.img_y);
    data->img.f_addr = mlx_get_data_addr(
        data->img.f_img_ptr,
        &data->img.f_bits_per_pixel,
        &data->img.f_size_line,
        &data->img.f_endian);
    copy_image(&(data)->img);
    for (int x = 0; x < data->img.img_x; x++)
    {
        double cameraX = 2 * x / (double)data->img.img_x - 1;
        double rayDirX = data->player.dirX + data->player.planeX * cameraX;
        double rayDirY = data->player.dirY + data->player.planeY * cameraX;

        int mapX = (int)data->player.x;
        int mapY = (int)data->player.y;

        double sideDistX;
        double sideDistY;

        double deltaDistX = fabs(1 / rayDirX);
        double deltaDistY = fabs(1 / rayDirY);
        double perpWallDist;

        int stepX, stepY;
        int hit = 0;
        int side;

        if (rayDirX < 0)
        {
            stepX = -1;
            sideDistX = (data->player.x - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - data->player.x) * deltaDistX;
        }

        if (rayDirY < 0)
        {
            stepY = -1;
            sideDistY = (data->player.y - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - data->player.y) * deltaDistY;
        }

        while (hit == 0)
        {
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            if (data->map->tab[mapY][mapX] == '1') hit = 1;
        }

        if (side == 0)
            perpWallDist = (mapX - data->player.x + (1 - stepX) / 2) / rayDirX;
        else
            perpWallDist = (mapY - data->player.y + (1 - stepY) / 2) / rayDirY;

        int lineHeight = (int)(data->img.img_y / perpWallDist);

        int drawStart = -lineHeight / 2 + data->img.img_y / 2;
        if (drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + data->img.img_y / 2;
        if (drawEnd >= data->img.img_y) drawEnd = data->img.img_y - 1;

        int color = (side == 1) ? 0xAAAAAA : 0xFFFFFF;
        draw_vertical_line(data, x, drawStart, drawEnd, color);
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img.f_img_ptr, 0, 0);
    mlx_destroy_image(data->mlx, data->img.f_img_ptr);
}
