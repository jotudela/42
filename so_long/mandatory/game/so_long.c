/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:38:41 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/16 11:13:37 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	close_win(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    ft_mapclear(data->map);
    exit(0);
}

int Key_press(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
        close_win(data);
    return (0);
}

int	close_cross(t_data *data)
{
	close_win(data);
	return (0);
}

void    so_long(t_map **map)
{
    t_data  data;
    
    data.map = map;
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 1920, 1080, "so_long");
    mlx_key_hook(data.win, Key_press, &data);
    mlx_hook(data.win, 17, 0, close_cross, &data);
    mlx_loop(data.mlx);
    return ;
}
