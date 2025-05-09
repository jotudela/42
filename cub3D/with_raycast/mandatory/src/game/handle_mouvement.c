/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouvement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:26:06 by jotudela          #+#    #+#             */
/*   Updated: 2025/05/09 18:55:12 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	update_camera2(t_data *data, float rs, float oldx, float oldplx)
{
	oldx = data->player.dirx;
	data->player.dirx = data->player.dirx * cos(rs)
		- data->player.diry * sin(rs);
	data->player.diry = oldx * sin(rs)
		+ data->player.diry * cos(rs);
	oldplx = data->player.planex;
	data->player.planex = data->player.planex * cos(rs)
		- data->player.planey * sin(rs);
	data->player.planey = oldplx * sin(rs) + data->player.planey * cos(rs);
}

void	update_camera(t_data *data)
{
	float	rs;
	float	oldx;
	float	oldplx;

	rs = data->player.rot;
	if (data->keys.left)
	{
		oldx = data->player.dirx;
		data->player.dirx = data->player.dirx * cos(-rs)
			- data->player.diry * sin(-rs);
		data->player.diry = oldx * sin(-rs) + data->player.diry * cos(-rs);
		oldplx = data->player.planex;
		data->player.planex = data->player.planex * cos(-rs)
			- data->player.planey * sin(-rs);
		data->player.planey = oldplx * sin(-rs)
			+ data->player.planey * cos(-rs);
	}
	if (data->keys.right)
		update_camera2(data, rs, oldx, oldplx);
}

static void	handle_movement_loop2(t_data *data, float ms, float nx, float ny)
{
	if (data->keys.a)
	{
		nx = data->player.x - data->player.planex * ms;
		ny = data->player.y - data->player.planey * ms;
		if (is_walkable(data, nx, data->player.y))
			data->player.x = nx;
		if (is_walkable(data, data->player.x, ny))
			data->player.y = ny;
	}
	if (data->keys.d)
	{
		nx = data->player.x + data->player.planex * ms;
		ny = data->player.y + data->player.planey * ms;
		if (is_walkable(data, nx, data->player.y))
			data->player.x = nx;
		if (is_walkable(data, data->player.x, ny))
			data->player.y = ny;
	}
	if (data->keys.left || data->keys.right)
		update_camera(data);
}

void	handle_movement_loop(t_data *data)
{
	float	ms;
	float	nx;
	float	ny;

	ms = data->player.move;
	if (data->keys.w)
	{
		nx = data->player.x + data->player.dirx * ms;
		ny = data->player.y + data->player.diry * ms;
		if (is_walkable(data, nx, data->player.y))
			data->player.x = nx;
		if (is_walkable(data, data->player.x, ny))
			data->player.y = ny;
	}
	if (data->keys.s)
	{
		nx = data->player.x - data->player.dirx * ms;
		ny = data->player.y - data->player.diry * ms;
		if (is_walkable(data, nx, data->player.y))
			data->player.x = nx;
		if (is_walkable(data, data->player.x, ny))
			data->player.y = ny;
	}
	handle_movement_loop2(data, ms, nx, ny);
}
