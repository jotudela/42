/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_clear_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:38:16 by jotudela          #+#    #+#             */
/*   Updated: 2025/05/07 18:48:32 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void put_pixel2(char *data, int x, int y, int color, int size_line, int bpp)
{
    int i;

    i = (y * size_line) + (x * (bpp / 8));
    data[i + 0] = (color & 0x000000FF);
    data[i + 1] = (color & 0x0000FF00) >> 8;
    data[i + 2] = (color & 0x00FF0000) >> 16;
}

static void ft_draw_img1(t_data ** data)
{
    int y;
    int x;
    int color;

    y = 0;
    color = 0x00000000;
    while (y < (*data)->img.img_y)
    {
        x = 0;
        while (x < (*data)->img.img_x)
        {
            put_pixel2((*data)->img.addr, x, y, color,
                    (*data)->img.size_line, (*data)->img.bits_per_pixel);
            x++;
        }
        y++;
    }
}

void    create_clear_img(t_data **data)
{
    void    *img_ptr;
    char    *addr;
    int     bits_per_pixel = 0;
    int     size_line = 0;
    int     endian = 0;
    img_ptr = mlx_new_image((*data)->mlx, (*data)->img.img_x, (*data)->img.img_y);
    if (!img_ptr)
        (free_data(data), error("Error\nCreate new image failed !\n"), exit(1));
    addr = mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);
    ft_draw_img1(data);
    mlx_put_image_to_window((*data)->mlx, (*data)->win, img_ptr, 0, 0);
    mlx_destroy_image((*data)->mlx, img_ptr);
}
