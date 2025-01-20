/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:38:41 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/20 18:14:00 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void generate(t_data *data, t_map *map)
{
    data->mlx = mlx_init();
    if (!data->mlx)
    {
        ft_printf("MLX init failed !\n");
        return ft_mapclear(data->map);
    }
    if (generate_textures(data) == 1)
    {
        ft_printf("Textures failed !\n");
        ft_mapclear(data->map);
        close_win(data);
    }
    data->win = mlx_new_window(data->mlx, map->len_line * 32, data->len_lst * 32, "so_long");
    if (!data->win)
    {
        ft_printf("Window failed !\n");
        ft_mapclear(data->map);
        close_win(data);
    }
}

void    so_long(t_map **map)
{
    t_data  data;
    
    data.map = map;
    data.len_lst = ft_lstlen(*map);
    generate(&data, *map);
    print_map(&data, *data.map);
    mlx_key_hook(data.win, Key_press, &data);
    mlx_hook(data.win, 17, 0, close_cross, &data);
    mlx_loop(data.mlx);
    return ;
}
