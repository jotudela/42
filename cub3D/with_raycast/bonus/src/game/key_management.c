/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:24:16 by jotudela          #+#    #+#             */
/*   Updated: 2025/05/09 18:06:02 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	key_press2(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		data->is_game = 0;
		data->is_paused = 1;
		create_clear_img(&data);
		draw_pause_menu(data);
	}
	if (keycode == XK_m)
	{
		data->is_game = 0;
		data->is_map = 1;
	}
	return (0);
}

static int	key_press3(int keycode, t_data *data)
{
	if (keycode == XK_Escape || keycode == XK_1)
	{
		data->is_paused = 0;
		data->is_game = 1;
		create_clear_img(&data);
		raycasting(data);
	}
	else if (keycode == XK_2)
	{
		printf("Bye !\n");
		free_data(&data);
		exit(0);
	}
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == XK_w)
		data->keys.w = 1;
	if (keycode == XK_a)
		data->keys.a = 1;
	if (keycode == XK_s)
		data->keys.s = 1;
	if (keycode == XK_d)
		data->keys.d = 1;
	if (keycode == XK_Left)
		data->keys.left = 1;
	if (keycode == XK_Right)
		data->keys.right = 1;
	if (data->is_game)
		key_press2(keycode, data);
	else if (data->is_map && keycode == XK_m)
	{
		data->is_map = 0;
		data->is_game = 1;
	}
	else if (data->is_paused)
		key_press3(keycode, data);
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == XK_w)
		data->keys.w = 0;
	if (keycode == XK_a)
		data->keys.a = 0;
	if (keycode == XK_s)
		data->keys.s = 0;
	if (keycode == XK_d)
		data->keys.d = 0;
	if (keycode == XK_Left)
		data->keys.left = 0;
	if (keycode == XK_Right)
		data->keys.right = 0;
	return (0);
}

int	game_loop(t_data *data)
{
	if (data->is_game)
	{
		handle_movement_loop(data);
		raycasting(data);
	}
	else if (data->is_map)
		handle_map_input(data);
	return (0);
}
