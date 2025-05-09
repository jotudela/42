/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:24:16 by jotudela          #+#    #+#             */
/*   Updated: 2025/05/09 09:38:04 by jotudela         ###   ########.fr       */
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

static void	update_camera(t_data *data, int mode)
{
    float	rotSpeed;
    if (mode == 1) rotSpeed = data->player.rot;
    else rotSpeed = data->player.rot;
	float	olddirx;
	float	oldplanex;

	if (data->keys.left)
	{
		olddirx = data->player.dirx;
		data->player.dirx = data->player.dirx * cos(-rotSpeed) - data->player.diry * sin(-rotSpeed);
		data->player.diry = olddirx * sin(-rotSpeed) + data->player.diry * cos(-rotSpeed);
		oldplanex = data->player.planex;
		data->player.planex = data->player.planex * cos(-rotSpeed) - data->player.planey * sin(-rotSpeed);
		data->player.planey = oldplanex * sin(-rotSpeed) + data->player.planey * cos(-rotSpeed);
	}
	if (data->keys.right)
	{
		olddirx = data->player.dirx;
		data->player.dirx = data->player.dirx * cos(rotSpeed) - data->player.diry * sin(rotSpeed);
		data->player.diry = olddirx * sin(rotSpeed) + data->player.diry * cos(rotSpeed);
		oldplanex = data->player.planex;
		data->player.planex = data->player.planex * cos(rotSpeed) - data->player.planey * sin(rotSpeed);
		data->player.planey = oldplanex * sin(rotSpeed) + data->player.planey * cos(rotSpeed);
	}
}

static int	is_walkable(t_data *data, float x, float y)
{
	int	map_x = (int)x;
	int	map_y = (int)y;

	if (map_x < 0 || map_x >= data->map->len_x || map_y < 0 || map_y >= data->map->len_y - 1)
		return (0);
	return (data->map->tab[map_y][map_x] == '0');
}

void	handle_movement_loop(t_data *data, int mode)
{
	float	moveSpeed;
    if (mode == 1) moveSpeed = data->player.move;
    else moveSpeed = data->player.move;
	float	newX, newY;

	if (data->keys.w)
	{
		newX = data->player.x + data->player.dirx * moveSpeed;
		newY = data->player.y + data->player.diry * moveSpeed;
		if (is_walkable(data, newX, data->player.y)) data->player.x = newX;
		if (is_walkable(data, data->player.x, newY)) data->player.y = newY;
	}
	if (data->keys.s)
	{
		newX = data->player.x - data->player.dirx * moveSpeed;
		newY = data->player.y - data->player.diry * moveSpeed;
		if (is_walkable(data, newX, data->player.y)) data->player.x = newX;
		if (is_walkable(data, data->player.x, newY)) data->player.y = newY;
	}
	if (data->keys.a)
	{
		newX = data->player.x - data->player.planex * moveSpeed;
		newY = data->player.y - data->player.planey * moveSpeed;
		if (is_walkable(data, newX, data->player.y)) data->player.x = newX;
		if (is_walkable(data, data->player.x, newY)) data->player.y = newY;
	}
	if (data->keys.d)
	{
		newX = data->player.x + data->player.planex * moveSpeed;
		newY = data->player.y + data->player.planey * moveSpeed;
		if (is_walkable(data, newX, data->player.y)) data->player.x = newX;
		if (is_walkable(data, data->player.x, newY)) data->player.y = newY;
	}
	if (data->keys.left || data->keys.right)
		update_camera(data, mode);
}

static void	handle_map_input(t_data *data)
{
	handle_movement_loop(data, 0);
	float	player_px = data->player.x * 30.0f;
	float	player_py = data->player.y * 30.0f;
	int		win_center_x = 1280 / 2;
	int		win_center_y = 720 / 2;
	int		map_draw_x = (int)(win_center_x - player_px);
	int		map_draw_y = (int)(win_center_y - player_py);

    create_clear_img(&data);
	mlx_put_image_to_window(data->mlx, data->win, data->minimap.m_img_ptr, map_draw_x, map_draw_y);
	draw_player(data, &data->player, 30);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == XK_w) data->keys.w = 1;
	if (keycode == XK_a) data->keys.a = 1;
	if (keycode == XK_s) data->keys.s = 1;
	if (keycode == XK_d) data->keys.d = 1;
	if (keycode == XK_Left) data->keys.left = 1;
	if (keycode == XK_Right) data->keys.right = 1;

	if (data->is_game)
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
	}
	else if (data->is_map && keycode == XK_m)
	{
		data->is_map = 0;
		data->is_game = 1;
	}
	else if (data->is_paused)
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
	}
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == XK_w) data->keys.w = 0;
	if (keycode == XK_a) data->keys.a = 0;
	if (keycode == XK_s) data->keys.s = 0;
	if (keycode == XK_d) data->keys.d = 0;
	if (keycode == XK_Left) data->keys.left = 0;
	if (keycode == XK_Right) data->keys.right = 0;
	return (0);
}

int	game_loop(t_data *data)
{
	if (data->is_game)
	{
		handle_movement_loop(data, 1);
		raycasting(data);
	}
	else if (data->is_map)
		handle_map_input(data);
	return (0);
}

int	close_cross(t_data *data)
{
	ft_printf("Bye !\n");
	free_data(&data);
	exit(0);
}
