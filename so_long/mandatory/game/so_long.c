/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:38:41 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/16 16:46:34 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void    so_long(t_map **map)
{
    t_data  data;
    
    data.map = map;
    data.mlx = mlx_init();
    if (!data.mlx)
    {
        ft_printf("MLX init failed !\n");
        return ft_mapclear(map);
    }
    if (generate_textures(&data) == 1)
    {
        ft_printf("Textures failed !\n");
        return ft_mapclear(map), mlx_destroy_display(data.mlx), free(data.mlx);
    }
    data.win = mlx_new_window(data.mlx, 1920, 1080, "so_long");
    if (!data.win)
    {
        ft_printf("Window failed !\n");
        return ft_mapclear(map), mlx_destroy_display(data.mlx), free(data.mlx);
    }
    print_map(&data, *data.map);
    mlx_key_hook(data.win, Key_press, &data);
    mlx_hook(data.win, 17, 0, close_cross, &data);
    mlx_loop(data.mlx);
    return ;
}
