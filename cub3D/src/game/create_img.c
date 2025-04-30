/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:38:32 by jotudela          #+#    #+#             */
/*   Updated: 2025/04/30 14:03:27 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void put_pixel(char *data, int x, int y, int color, int size_line, int bpp)
{
    int i;

    i = (y * size_line) + (x * (bpp / 8));
    data[i + 0] = (color & 0x000000FF);
    data[i + 1] = (color & 0x0000FF00) >> 8;
    data[i + 2] = (color & 0x00FF0000) >> 16;
}

static void ft_draw_img(t_data ** data)
{
    int y;
    int x;
    int color;

    y = 0;
    while (y < (*data)->img.img_y)
    {
        x = 0;
        while (x < (*data)->img.img_x)
        {
            if (y < (*data)->img.img_y / 2)
                color = (*data)->img.C;
            else
                color = (*data)->img.F;
            put_pixel((*data)->img.addr, x, y, color,
                    (*data)->img.size_line, (*data)->img.bits_per_pixel);
            x++;
        }
        y++;
    }
}

void    create_img(t_data **data)
{
    (*data)->img.img_ptr = mlx_new_image((*data)->mlx, (*data)->img.img_x, (*data)->img.img_y);
    if (!(*data)->img.img_ptr)
        (free_data(data), error("Error\nCreate new image failed !\n"), exit(1));
    (*data)->img.addr = mlx_get_data_addr((*data)->img.img_ptr,
                                            &(*data)->img.bits_per_pixel,
                                            &(*data)->img.size_line,
                                            &(*data)->img.endian);
    if (!(*data)->img.addr)
        (free_data(data), error("Error\nGet addr of image failed !\n"), exit(1));
    ft_draw_img(data);
}
