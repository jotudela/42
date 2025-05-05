/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:04:45 by jotudela          #+#    #+#             */
/*   Updated: 2025/05/05 14:05:41 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void draw_vertical_line(t_data *data, int x, int drawStart, int drawEnd, int color)
{
    for (int y = drawStart; y <= drawEnd; y++)
        mlx_pixel_put(data->mlx, data->win, x, y, color);
}

void raycasting(t_data *data)
{
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
}
