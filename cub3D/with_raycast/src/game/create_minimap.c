/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:19:13 by jotudela          #+#    #+#             */
/*   Updated: 2025/05/07 17:32:29 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void put_pixel_to_image(t_minimap *img, int x, int y, int color)
{
    if (x < 0 || y < 0 || x >= 1280 * 30 || y >= 720 * 30)
        return; // évite le dépassement
    char *dst = img->m_pixels + (y * img->m_line_length + x * (img->m_bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void draw_square_to_image(t_minimap *img, int x, int y, int size, int color)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            // Bord du carré
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1)
                put_pixel_to_image(img, x + j, y + i, 0x444444); // gris pour le quadrillage
            else
                put_pixel_to_image(img, x + j, y + i, color);
        }
    }
}

void render_map_to_image(t_minimap *img, char **map, int tile_size)
{
    for (int y = 0; map[y]; y++)
    {
        for (int x = 0; map[y][x]; x++)
        {
            int color;
            if (map[y][x] == '1')
            color = 0xFFFFFF; // murs blancs
            else if (map[y][x] == '0')
                color = 0x000000; // sol noir
            else
                continue;
            draw_square_to_image(img, x * tile_size, y * tile_size, tile_size, color);
        }
    }
}

void create_minimap(t_data **data)
{
    int tile_size = 30;
    int image_width = 1280;
    int image_height = 720;

    (*data)->minimap.m_img_ptr = mlx_new_image((*data)->mlx, image_width, image_height);
    (*data)->minimap.m_pixels = mlx_get_data_addr(
        (*data)->minimap.m_img_ptr,
        &(*data)->minimap.m_bits_per_pixel,
        &(*data)->minimap.m_line_length,
        &(*data)->minimap.m_endian);

    render_map_to_image(&(*data)->minimap, (*data)->map->tab, tile_size);
}
