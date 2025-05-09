/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:38:32 by jotudela          #+#    #+#             */
/*   Updated: 2025/05/09 12:10:08 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*static int get_pixel_color(t_image *img, int x, int y)
{
	char *pixel;

	if (x < 0 || x >= img->img_x || y < 0 || y >= img->img_y)
		return (0); // ou couleur par défaut

	pixel = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
}*/

static void put_pixel_to_image2(t_image *img, int x, int y, int color)
{
    char *dst;

    if (x < 0 || x >= img->img_x || y < 0 || y >= img->img_y)
        return;

    int real_y = y;
    if (img->size_line < 0)
        real_y = img->img_y - 1 - y;

    dst = img->addr + (real_y * abs(img->size_line) + x * (img->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void draw_walls(t_data *data, int x, int drawStart, int drawEnd, t_tex_info *tex, int texX, int lineHeight)
{
    int y, d, texY;
    unsigned int color;

    for (y = drawStart; y < drawEnd; y++)
    {
        d = y * 256 - data->img.img_y * 128 + lineHeight * 128;
        texY = ((d * tex->height) / lineHeight) / 256;

        if (texY < 0)
            texY = 0;
        if (texY >= tex->height)
            texY = tex->height - 1;

        color = *(unsigned int *)(tex->addr +
            (texY * tex->size_line + texX * (tex->bits_per_pixel / 8)));
        put_pixel_to_image2(&data->img, x, y, color);
    }
}


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
                color = (*data)->img.c;
            else
                color = (*data)->img.f;
            put_pixel((*data)->img.addr, x, y, color,
                    (*data)->img.size_line, (*data)->img.bits_per_pixel);
            x++;
        }
        y++;
    }
}

void    create_img_background(t_data **data)
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
