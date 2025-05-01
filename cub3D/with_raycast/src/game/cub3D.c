/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:13:51 by jotudela          #+#    #+#             */
/*   Updated: 2025/05/01 11:22:21 by jotudela         ###   ########.fr       */
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

static void generate(t_data **data)
{
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
}

void    cub3d(t_data **data)
{
    generate(data);
    mlx_put_image_to_window((*data)->mlx, (*data)->win, (*data)->img.img_ptr, 0, 0);
    mlx_key_hook((*data)->win, key_press, *data);
    mlx_hook((*data)->win, 17, 0, close_cross, *data);
    mlx_loop((*data)->mlx);
}
