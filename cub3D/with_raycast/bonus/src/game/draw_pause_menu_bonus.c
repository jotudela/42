/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pause_menu_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:38:49 by jotudela          #+#    #+#             */
/*   Updated: 2025/05/13 11:27:16 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

void	draw_pause_menu(t_data *data)
{
	mlx_string_put(data->mlx, data->win, data->img.img_x / 2 - 40,
		data->img.img_y / 2 - 30, 0xFFFFFF, "Continuer (1)");
	mlx_string_put(data->mlx, data->win, data->img.img_x / 2 - 30,
		data->img.img_y / 2 + 10, 0xFFFFFF, "Quitter (2)");
}
