/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:13:51 by jotudela          #+#    #+#             */
/*   Updated: 2025/05/05 14:05:27 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int  generate_textures(t_data **data)
{
    (*data)->img.x = 32;
    (*data)->img.y = 32;
    (*data)->img.NO = mlx_xpm_file_to_image((*data)->mlx,
                    (*data)->img.path_NO,
                    &(*data)->img.x,
                    &(*data)->img.y);
    (*data)->img.SO = mlx_xpm_file_to_image((*data)->mlx,
                    (*data)->img.path_SO,
                    &(*data)->img.x,
                    &(*data)->img.y);
    (*data)->img.WE = mlx_xpm_file_to_image((*data)->mlx,
                    (*data)->img.path_WE,
                    &(*data)->img.x,
                    &(*data)->img.y);
    (*data)->img.EA = mlx_xpm_file_to_image((*data)->mlx,
                    (*data)->img.path_EA,
                    &(*data)->img.x,
                    &(*data)->img.y);
    if (!(*data)->img.NO || !(*data)->img.SO
        || !(*data)->img.WE || !(*data)->img.EA)
        return (-1);
    return (0);
}

static void init_player2(t_data **data, int x, int y)
{
    if ((*data)->map->tab[y][x] == 'E')
    {
        (*data)->player.dirX = 1;
        (*data)->player.dirY = 0;
        (*data)->player.planeX = 0;
        (*data)->player.planeY = -0.66;
    }
}

static void init_player(t_data **data, int x, int y)
{
    if ((*data)->map->tab[y][x] == 'N')
    {
        (*data)->player.dirX = 0;
        (*data)->player.dirY = -1;
        (*data)->player.planeX = 0.66;
        (*data)->player.planeY = 0;
    }
    if ((*data)->map->tab[y][x] == 'S')
    {
        (*data)->player.dirX = 0;
        (*data)->player.dirY = 1;
        (*data)->player.planeX = -0.66;
        (*data)->player.planeY = 0;
    }
    if ((*data)->map->tab[y][x] == 'W')
    {
        (*data)->player.dirX = -1;
        (*data)->player.dirY = 0;
        (*data)->player.planeX = 0;
        (*data)->player.planeY = 0.66;
    }
    init_player2(data, x, y);
    (*data)->map->tab[y][x] = '0';
}

static void generate(t_data **data)
{
    (*data)->player.x = (*data)->map->map_x;
    (*data)->player.y = (*data)->map->map_y;
    init_player(data, (*data)->map->map_x, (*data)->map->map_y);
    (*data)->mlx = mlx_init();
    if (!(*data)->mlx)
        (free_data(data), error("Error\nMLX inti failed !\n"), exit(1));
    if (mlx_get_screen_size((*data)->mlx, &(*data)->img.img_x, &(*data)->img.img_y) == 1)
        (free_data(data), error("Error\nGet screen size failed !\n"), exit(1));
    (*data)->img.img_x /= 3;
    (*data)->img.img_y /= 3;
    if (generate_textures(data) == -1)
        (free_data(data), error("Error\nFailed to generate textures !\n"), exit(1));
    (*data)->win = mlx_new_window((*data)->mlx,
                    (*data)->img.img_x, (*data)->img.img_y, "TEST");
    if (!(*data)->win)
        (free_data(data), error("Error\nGenerate new window failed !\n"), exit(1));
    create_img(data);
    create_minimap(data);
}

void    cub3d(t_data **data)
{
    generate(data);
    mlx_put_image_to_window((*data)->mlx, (*data)->win, (*data)->img.img_ptr, 0, 0);
    raycasting(*data);
    mlx_hook((*data)->win, 2, 1L << 0, key_press, *data);
    mlx_hook((*data)->win, 3, 1L << 1, key_release, *data);
    mlx_hook((*data)->win, 17, 0, close_cross, *data);
    mlx_loop((*data)->mlx);
}
