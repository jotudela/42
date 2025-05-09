/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:04:45 by jotudela          #+#    #+#             */
/*   Updated: 2025/05/09 12:10:23 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void raycasting(t_data *data)
{
    create_img_background(&data);
    for (int x = 0; x < data->img.img_x; x++)
    {
        t_raycast r;
        r.cameraX = 2 * x / (float)data->img.img_x - 1;
        r.rayDirX = data->player.dirx + data->player.planex * r.cameraX;
        r.rayDirY = data->player.diry + data->player.planey * r.cameraX;

        r.mapX = (int)data->player.x;
        r.mapY = (int)data->player.y;

        r.deltaDistX = fabs(1 / r.rayDirX);
        r.deltaDistY = fabs(1 / r.rayDirY);
        r.hit = 0;

        if (r.rayDirX < 0)
        {
            r.stepX = -1;
            r.sideDistX = (data->player.x - r.mapX) * r.deltaDistX;
        }
        else
        {
            r.stepX = 1;
            r.sideDistX = (r.mapX + 1.0 - data->player.x) * r.deltaDistX;
        }

        if (r.rayDirY < 0)
        {
            r.stepY = -1;
            r.sideDistY = (data->player.y - r.mapY) * r.deltaDistY;
        }
        else
        {
            r.stepY = 1;
            r.sideDistY = (r.mapY + 1.0 - data->player.y) * r.deltaDistY;
        }

        while (r.hit == 0)
        {
            if (r.sideDistX < r.sideDistY)
            {
                r.sideDistX += r.deltaDistX;
                r.mapX += r.stepX;
                r.side = 0;
            }
            else
            {
                r.sideDistY += r.deltaDistY;
                r.mapY += r.stepY;
                r.side = 1;
            }
            if (r.mapY < 0 || r.mapY >= data->map->len_y ||
                r.mapX < 0 || r.mapX >= data->map->len_x ||
                data->map->tab[r.mapY][r.mapX] == '1' ||
                data->map->tab[r.mapY][r.mapX] == ' ')
                r.hit = 1;
        }

        if (r.side == 0)
            r.perpWallDist = (r.mapX - data->player.x + (1 - r.stepX) / 2) / r.rayDirX;
        else
            r.perpWallDist = (r.mapY - data->player.y + (1 - r.stepY) / 2) / r.rayDirY;

        r.lineHeight = (int)(data->img.img_y / r.perpWallDist);
        r.drawStart = -r.lineHeight / 2 + data->img.img_y / 2;
        if (r.drawStart < 0) r.drawStart = 0;
        r.drawEnd = r.lineHeight / 2 + data->img.img_y / 2;
        if (r.drawEnd >= data->img.img_y) r.drawEnd = data->img.img_y - 1;

        t_tex_info *tex;

        if (r.side == 0) // Mur vertical (NS)
            tex = (r.rayDirX > 0) ? &data->img.ea : &data->img.we;
        else            // Mur horizontal (EW)
            tex = (r.rayDirY > 0) ? &data->img.so : &data->img.no;

        r.wallX = (r.side == 0) ? data->player.y + r.perpWallDist * r.rayDirY : data->player.x + r.perpWallDist * r.rayDirX;
        r.wallX -= floor(r.wallX);

        // Calcul de texX pour toutes les textures
        r.texX = (int)(r.wallX * tex->width);

        // Inverser texX pour NO et SO en fonction de la direction
        if (tex == &data->img.we) // Si c'est un mur Nord et le rayon va vers le haut
            r.texX = tex->width - r.texX - 1;
        else if (tex == &data->img.so) // Si c'est un mur Sud et le rayon va vers le bas
            r.texX = tex->width - r.texX - 1;

        // Ajustement de la position de la texture pour l'affichage
        draw_walls(data, x, r.drawStart, r.drawEnd, tex, r.texX, r.lineHeight);
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
    mlx_destroy_image(data->mlx, data->img.img_ptr);
}
