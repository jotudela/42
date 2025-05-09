/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pause_menu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:38:49 by jotudela          #+#    #+#             */
/*   Updated: 2025/05/09 16:39:13 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_pause_menu(t_data *data)
{
	mlx_string_put(data->mlx, data->win, data->img.img_x / 2 - 40,
		data->img.img_y / 2 - 30, 0xFFFFFF, "Continuer (1)");
	mlx_string_put(data->mlx, data->win, data->img.img_x / 2 - 30,
		data->img.img_y / 2 + 10, 0xFFFFFF, "Quitter (2)");
}
